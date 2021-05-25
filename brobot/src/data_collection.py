#!/usr/bin/python
import os
import time
import rospy
from std_msgs.msg import Bool
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2

# Instantiate CvBridge
bridge = CvBridge()


class DataCollect:
    def __init__(self):
        self.collection_active = None
        self.time_interval = 0.1
        self.timestr = None
        self.cv2_img = None
        self.img_index = 0

    def save_data(self, timer):
        if self.collection_active == True:
            cv2.imwrite('/media/nuc/aaac50a8-6183-4b03-a5be-34cf403af78e/temp/'+str('%07d' % self.img_index)+'.jpeg', self.cv2_img)
            self.img_index = self.img_index + 1
    def data_trigger_callback(self, trigger_state):
        if self.collection_active == None:
            print('Waiting for user')
            if trigger_state.data == False:
                self.collection_active = False
            else:
                print('Please start dwith data collection switch off...')
        else:
            if self.collection_active != trigger_state.data:
                self.collection_active = trigger_state.data
                if  self.collection_active == True:
                    self.timestr = time.strftime("%Y%m%d_%H%M%S")
                    #os.system('mkdir ' + '/media/nuc/9c4f5567-9e77-45bf-ba94-a0ab33e13294/brobot_data/temp')
                    os.mkdir('/media/nuc/aaac50a8-6183-4b03-a5be-34cf403af78e/temp', 0777)
                    os.chmod('/media/nuc/aaac50a8-6183-4b03-a5be-34cf403af78e/temp', 0777)
                    print('creating temp folder')
                    print('saving images')
                else:
                    os.rename('/media/nuc/aaac50a8-6183-4b03-a5be-34cf403af78e/temp', '/media/nuc/aaac50a8-6183-4b03-a5be-34cf403af78e/' + self.timestr)
                    os.chmod('/media/nuc/aaac50a8-6183-4b03-a5be-34cf403af78e/' + self.timestr, 0777)
                    self.img_index = 0
                    print('stopping data collection')
                    print('renaming temp folder: ' + str(self.timestr))


    def image_callback(self, msg):
        #print("Received an image!")
        try:
            # Convert your ROS Image message to OpenCV2
            self.cv2_img = bridge.imgmsg_to_cv2(msg, "bgr8")
        except CvBridgeError, e:
            print(e)


def subscribe_to_topics():
    rospy.Subscriber('data_trigger', Bool, data_collect.data_trigger_callback)
    rospy.Timer(rospy.Duration(data_collect.time_interval), data_collect.save_data)
    # Define your image topic
    image_topic = "/camera_array/cam0/image_raw"
    # Set up your subscriber and define its callback
    rospy.Subscriber(image_topic, Image, data_collect.image_callback)
    rospy.spin()


################################################################################


if __name__ == "__main__":
    rospy.init_node('data_collection', anonymous=True)
    data_collect = DataCollect()

    subscribe_to_topics()
