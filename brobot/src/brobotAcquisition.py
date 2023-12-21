#brobot acquisition
#Joseph Cristiano 8/22/23
#Jumping off from the AcquisitionMultipleCamera.py example in Spinnaker Python library

#Libraries included for AcquisitionMultipleCamera.py
import os
import PySpin
import sys
#Libraries for our use-case
import rclpy
import time
from rclpy.node import Node
from std_msgs.msg import Bool
import threading 
import queue
r_acquisition_state = False
l_acquisition_state = False

R_CAM_SN = 23185348
L_CAM_SN = 22624783

class RosReader(Node):
    def __init__(self):
      super().__init__('brobot_acquisition_node')
      self.r_cam_sub = self.create_subscription(Bool, '/righteye_cmd', self.r_listener_callback , 10)
      self.l_cam_sub = self.create_subscription(Bool, '/lefteye_cmd', self.l_listener_callback , 10)
      ##can probably add an action or another listener that can do the camera cleanup and exit if we so desire
    #global r_listener_callback
    #global l_listener_callback
    def r_listener_callback(self, msg):
        global r_acquisition_state
        r_acquisition_state = msg.data
    def l_listener_callback(self, msg):
        global l_acquisition_state
        l_acquisition_state = msg.data

def fetch_camera_frames(result, cam, processor,side):
    print("fetch_camera_frames was called for: ", side)
    images = list()
    state = True
    while(state):
        if side == "right":
            global r_acquisition_state
            state = r_acquisition_state
        if side == "left":
            global l_acquisition_state
            state = l_acquisition_state
        #get the data
        print("While loop is running with state = ", state)
        image_result = cam.GetNextImage(1000)
        if image_result.IsIncomplete():
            print('Image incomplete with image status %d ... \n' % image_result.GetImageStatus())
        else:
            # Print image information
            # width = image_result.GetWidth()
            # height = image_result.GetHeight()
            # print('Camera %d grabbed image %d, width = %d, height = %d' % (i, l_img_series_count, width, height)
            # Convert image to PixelFormat_RGB8
            images.append(processor.Convert(image_result, PySpin.PixelFormat_RGB8))
            # Release image 
            image_result.Release()
    result.put(images)
    print("fetch_camera_frames has ended")
    
def store_images(images,side):
    print("store_images was called for: ", side)
    if side == "right":
        file_location = "/spinPics/rightCam/"
    if side == "left":
        file_location = "/spinPics/leftCam/"
    img_series_str = time.strftime("%Y%m%d_%H%M%S")
    os.mkdir(file_location + img_series_str, 0o777)
    os.chmod(file_location + img_series_str, 0o777)
    for i, img in enumerate(images.get()):
        filename = '%s%s/%d.jpg' % (file_location,img_series_str,i)
        img.Save(filename)
    print("store_images has completed")



def acquire_images(cam_list):
    """
    :param cam_list: List of cameras
    :type cam_list: CameraList
    :return: True if successful, False otherwise.
    :rtype: bool
    """
    rclpy.init()
    ros_reader_node = RosReader()

    print('*** IMAGE ACQUISITION ***\n')
    try:
        result = True

        # Prepare each camera to acquire images
        #
        # *** NOTES ***
        # For pseudo-simultaneous streaming, each camera is prepared as if it
        # were just one, but in a loop. Notice that cameras are selected with
        # an index. We demonstrate pseduo-simultaneous streaming because true
        # simultaneous streaming would require multiple process or threads,
        # which is too complex for an example.
        #

        for i, cam in enumerate(cam_list):
            s_node_map = cam.GetTLStreamNodeMap()
            # Set acquisition mode to continuous
            node_acquisition_mode = PySpin.CEnumerationPtr(cam.GetNodeMap().GetNode('AcquisitionMode'))
            if not PySpin.IsReadable(node_acquisition_mode) or not PySpin.IsWritable(node_acquisition_mode):
                print('Unable to set acquisition mode to continuous (node retrieval; camera %d). Aborting... \n' % i)
                return False

            node_acquisition_mode_continuous = node_acquisition_mode.GetEntryByName('Continuous')
            if not PySpin.IsReadable(node_acquisition_mode_continuous):
                print('Unable to set acquisition mode to continuous (entry \'continuous\' retrieval %d). \
                Aborting... \n' % i)
                return False
            handling_mode = PySpin.CEnumerationPtr(s_node_map.GetNode('StreamBufferHandlingMode'))
            if not PySpin.IsReadable(handling_mode) or not PySpin.IsWritable(handling_mode):
                print('Unable to set Buffer Handling mode (node retrieval). Aborting...\n')
                return False
            
            acquisition_mode_continuous = node_acquisition_mode_continuous.GetValue()

            node_acquisition_mode.SetIntValue(acquisition_mode_continuous)

            print('Camera %d acquisition mode set to continuous...' % i)

            handling_mode_entry = handling_mode.GetEntryByName('NewestOnly')
            handling_mode.SetIntValue(handling_mode_entry.GetValue())
            print('\n\nBuffer Handling Mode has been set to %s' % handling_mode_entry.GetDisplayName())
            
            # Begin acquiring images
            cam.BeginAcquisition()

            print('Camera %d started acquiring images...' % i)

            print()

        # Retrieve, convert, and save images for each camera
        #
        # *** NOTES ***
        # In order to work with simultaneous camera streams, nested loops are
        # needed. It is important that the inner loop be the one iterating
        # through the cameras; otherwise, all images will be grabbed from a
        # single camera before grabbing any images from another.

        # Create ImageProcessor instance for post processing images
        processor = PySpin.ImageProcessor()
        # Set default image processor color processing method
        #
        # *** NOTES ***
        # By default, if no specific color processing algorithm is set, the image
        # processor will default to NEAREST_NEIGHBOR method.
        processor.SetColorProcessing(PySpin.SPINNAKER_COLOR_PROCESSING_ALGORITHM_HQ_LINEAR)
        r_previous_state = False
        l_previous_state = False
        while(1):
            rclpy.spin_once(ros_reader_node) #spin the node, check for  messages
            global r_acquisition_state
            global l_acquisition_state
            for i, cam in enumerate(cam_list):
                try:
                    # Retrieve device serial number for filename
                    node_device_serial_number = PySpin.CStringPtr(cam.GetTLDeviceNodeMap().GetNode('DeviceSerialNumber'))
                    if PySpin.IsReadable(node_device_serial_number):
                        device_serial_number = node_device_serial_number.GetValue()
                        # print('Camera %d serial number set to %s...' % (i, device_serial_number))
                    ##based on serial number we can check which side and weather it should be acquiring
                    if int(device_serial_number) == int(L_CAM_SN):
                        if(l_acquisition_state and l_acquisition_state != l_previous_state):
                            ##call the fetch_camera_frames()
                            print("aquisition left turned on")
                            l_images = queue.Queue()
                            l_thread = threading.Thread(target=fetch_camera_frames,args=(l_images,cam,processor,"left"))
                            l_thread.start()
                            l_previous_state = l_acquisition_state 
                        elif(not l_acquisition_state and l_acquisition_state != l_previous_state):
                            ## can the join function here
                            ## then call storing thread here
                            print("aquisition left turned off")
                            l_thread.join()
                            l_store_thread = threading.Thread(target=store_images,args=(l_images,"left"))
                            l_store_thread.start()
                            l_previous_state = l_acquisition_state  
                        else:
                            l_previous_state = l_acquisition_state     
                    if int(device_serial_number) == int(R_CAM_SN):
                        if(r_acquisition_state and r_acquisition_state != r_previous_state): #if acquisition mode turned on 
                            ##call the fetch_camera_frames()
                            print("aquistition right turned on")
                            r_images = queue.Queue()
                            r_thread = threading.Thread(target=fetch_camera_frames,args=(r_images,cam,processor,"right"))
                            r_thread.start()
                            r_previous_state = r_acquisition_state
                        elif(not r_acquisition_state and r_acquisition_state != r_previous_state): # if acquisition mode turned off
                            ## can the join function here
                            ## then call storing thread here
                            print("aquisition right turned off")
                            r_thread.join()
                            r_store_thread = threading.Thread(target=store_images,args=(r_images,"right"))
                            r_store_thread.start()
                            r_previous_state = r_acquisition_state
                        else: # if no change in state
                            r_previous_state = r_acquisition_state
                
                except PySpin.SpinnakerException as ex:
                    print('Error: %s' % ex)
                    result = False               

        # End acquisition for each camera
        #
        # *** NOTES ***
        # Notice that what is usually a one-step process is now two steps
        # because of the additional step of selecting the camera. It is worth
        # repeating that camera selection needs to be done once per loop.
        #
        # It is possible to interact with cameras through the camera list with
        # GetByIndex(); this is an alternative to retrieving cameras as
        # CameraPtr objects that can be quick and easy for small tasks.

        ros_reader_node.destroy_node()
        rclpy.shutdown()
        print("rclpy shut down")

        for cam in cam_list:

            # End acquisition
            cam.EndAcquisition()

    except PySpin.SpinnakerException as ex:
        print('Error: %s' % ex)
        result = False

    return result


def print_device_info(nodemap, cam_num):
    """
    This function prints the device information of the camera from the transport
    layer; please see NodeMapInfo example for more in-depth comments on printing
    device information from the nodemap.

    :param nodemap: Transport layer device nodemap.
    :param cam_num: Camera number.
    :type nodemap: INodeMap
    :type cam_num: int
    :returns: True if successful, False otherwise.
    :rtype: bool
    """

    print('Printing device information for camera %d... \n' % cam_num)

    try:
        result = True
        node_device_information = PySpin.CCategoryPtr(nodemap.GetNode('DeviceInformation'))

        if PySpin.IsReadable(node_device_information):
            features = node_device_information.GetFeatures()
            for feature in features:
                node_feature = PySpin.CValuePtr(feature)
                print('%s: %s' % (node_feature.GetName(),
                                  node_feature.ToString() if PySpin.IsReadable(node_feature) else 'Node not readable'))

        else:
            print('Device control information not readable.')
            print()

    except PySpin.SpinnakerException as ex:
        print('Error: %s' % ex)
        return False

    return result

def run_multiple_cameras(cam_list):
    """
    This function acts as the body of the example; please see NodeMapInfo example
    for more in-depth comments on setting up cameras.

    :param cam_list: List of cameras
    :type cam_list: CameraList
    :return: True if successful, False otherwise.
    :rtype: bool
    """
    try:
        result = True

        # Retrieve transport layer nodemaps and print device information for
        # each camera
        # *** NOTES ***
        # This example retrieves information from the transport layer nodemap
        # twice: once to print device information and once to grab the device
        # serial number. Rather than caching the nodem#ap, each nodemap is
        # retrieved both times as needed.
        print('*** DEVICE INFORMATION ***\n')

        for i, cam in enumerate(cam_list):

            # Retrieve TL device nodemap
            nodemap_tldevice = cam.GetTLDeviceNodeMap()

            # Print device information
            result &= print_device_info(nodemap_tldevice, i)

        # Initialize each camera
        #
        # *** NOTES ***
        # You may notice that the steps in this function have more loops with
        # less steps per loop; this contrasts the AcquireImages() function
        # which has less loops but more steps per loop. This is done for
        # demonstrative purposes as both work equally well.
        #
        # *** LATER ***
        # Each camera needs to be deinitialized once all images have been
        # acquired.
        for i, cam in enumerate(cam_list):

            # Initialize camera
            cam.Init()

        # Acquire images on all cameras
        result &= acquire_images(cam_list)

        # Deinitialize each camera
        #
        # *** NOTES ***
        # Again, each camera must be deinitialized separately by first
        # selecting the camera and then deinitializing it.
        for cam in cam_list:

            # Deinitialize camera
            cam.DeInit()

        # Release reference to camera
        # NOTE: Unlike the C++ examples, we cannot rely on pointer objects being automatically
        # cleaned up when going out of scope.
        # The usage of del is preferred to assigning the variable to None.
        del cam

    except PySpin.SpinnakerException as ex:
        print('Error: %s' % ex)
        result = False

    return result


def main():
    """
    Example entry point; please see Enumeration example for more in-depth
    comments on preparing and cleaning up the system.

    :return: True if successful, False otherwise.
    :rtype: bool
    """

    # Since this application saves images in the current folder
    # we must ensure that we have permission to write to this folder.
    # If we do not have permission, fail right away.
    try:
        test_file = open('test.txt', 'w+')
    except IOError:
        print('Unable to write to current directory. Please check permissions.')
        input('Press Enter to exit...')
        return False

    test_file.close()
    os.remove(test_file.name)

    result = True

    # Retrieve singleton reference to system object
    system = PySpin.System.GetInstance()

    # Get current library version
    version = system.GetLibraryVersion()
    print('Library version: %d.%d.%d.%d' % (version.major, version.minor, version.type, version.build))

    # Retrieve list of cameras from the system
    cam_list = system.GetCameras()

    num_cameras = cam_list.GetSize()

    print('Number of cameras detected: %d' % num_cameras)

    # Finish if there are no cameras
    if num_cameras == 0:

        # Clear camera list before releasing system
        cam_list.Clear()

        # Release system instance
        system.ReleaseInstance()

        print('Not enough cameras!')
        input('Done! Press Enter to exit...')
        return False

    # Run example on all cameras
    print('Running example for all cameras...')

    result = run_multiple_cameras(cam_list)


    # Clear camera list before releasing system
    cam_list.Clear()

    # Release system instance
    system.ReleaseInstance()

    input('Done! Press Enter to exit...')
    return result

if __name__ == '__main__':
    if main():
        sys.exit(0)
    else:
        sys.exit(1)
