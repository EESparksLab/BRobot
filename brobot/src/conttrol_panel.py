#ROS interfacing with brobot control panel
import serial
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from std_msgs.msg import Float64
import glob
import os

previousState_l = False
previousState_r = False
previous_file_time_r = 0
previous_file_time_l = 0

ser = serial.Serial('/dev/ttyACM0',9600,timeout=1)

class RosReader(Node):
    def __init__(self):
      super().__init__('control_panel')
      self.cam_light_sub_r = self.create_subscription(Bool, '/righteye_cmd', toggle_LED_r , 10)
      self.cam_light_sub_l = self.create_subscription(Bool, '/lefteye_cmd', toggle_LED_l , 10)
      self.batt_LED_sub = self.create_subscription(Float64, '/battery', battery_LEDs , 10)


def toggle_LED_r(state):
    global previousState_r
    #print("r:",state)
    global previous_file_time_r
    if previous_file_time_r < filecheck("/spinPics/rightCam"):
        previous_file_time_r = filecheck("/spinPics/rightCam")
    elif(state.data == True and previousState_r == True):
            #The files are supposed to be written, something is wrong!!!
            #put code to flash warnings here, perhaps capital R, then arduino needs flash routine
            ser.write('R\n'.encode('utf-8')) #postcode to flash right light
            print("Error: no files from right camera!")


    if (state.data != previousState_r):
        if(state.data == True):
            ser.write('r'.encode('utf-8'))
            ser.write('\n'.encode('utf-8'))
        else:
            ser.write(']\n'.encode('utf-8'))
        previousState_r = not previousState_r


def toggle_LED_l(state):
    global previousState_l
    global previous_file_time_l
    if previous_file_time_l < filecheck("/spinPics/leftCam"):
        previous_file_time_l = filecheck("/spinPics/leftCam")
    elif(state.data == True and previousState_l == True):
            #The files are supposed to be written, something is wrong!!!
            #put code to flash warnings here, perhaps capital R, then arduino needs flash routine
            ser.write('L\n'.encode('utf-8')) #postcode to flash right light
            print("Error: no files from left camera!")

    if(state.data != previousState_l):
        #print("l:",state)
        if(state.data == True):
            ser.write('l'.encode('utf-8'))
            ser.write('\n'.encode('utf-8'))
        else:
            ser.write('[\n'.encode('utf-8'))

        previousState_l = not previousState_l


def battery_LEDs(voltage):
    print(voltage.data)


def filecheck(directory_path):

    # Get the list of all files in the directory
    files = glob.glob(directory_path + "/*")
    if len(files) == 0:
        return 0
    # Find the most recently created file
    newest_file = max(files, key=os.path.getctime)
    newest_file_time = os.path.getctime(newest_file)
    return newest_file_time

rclpy.init()
ros_reader_node = RosReader()
rclpy.spin(ros_reader_node)
ros_reader_node.destroy_node()
rclpy.shutdown()
print("rclpy shut down")
