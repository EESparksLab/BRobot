#!/usr/bin/python3
#ROS interfacing with brobot control panel
import serial
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from std_msgs.msg import Float64
previousState_l = False
previousState_r = False

ser = serial.Serial('/dev/ttyUSB0',9600,timeout=1)
print("Testing file output, conttrol_panel.py")

class RosReader(Node):
    def __init__(self):
      super().__init__('control_panel')
      self.cam_light_sub_r = self.create_subscription(Bool, '/righteye_cmd', toggle_LED_r , 10)
      self.cam_light_sub_l = self.create_subscription(Bool, '/lefteye_cmd', toggle_LED_l , 10)
      self.batt_LED_sub = self.create_subscription(Float64, '/battery', battery_LEDs , 10)
def toggle_LED_r(state):
    global previousState_r
    print("r:",state)
    if (state.data != previousState_r):
        ser.write('r'.encode('utf-8'))
        ser.write('\n'.encode('utf-8'))
        previousState_r = not previousState_r
def toggle_LED_l(state):
    global previousState_l
    if(state.data != previousState_l):
        print("l:",state)
        ser.write('l'.encode('utf-8'))
        ser.write('\n'.encode('utf-8'))
        previousState_l = not previousState_l

def battery_LEDs(voltage):
    print(voltage.data)




rclpy.init()
ros_reader_node = RosReader()
rclpy.spin(ros_reader_node)
ros_reader_node.destroy_node()
rclpy.shutdown()
print("rclpy shut down")
