#ROS interfacing with brobot control panel
import serial
from rclpy.node import Node
from std_msgs.msg import Bool

ser = serial.Serial('/dev/ttyACM0',9600,timeout=1)

class RosReader(Node):
    def __init__(self):
      super().__init__('control_panel')
      self.cam_light_sub_r = self.create_subscription(Bool, '/righteye_cmd', toggle_LED_r , 10)
      self.cam_light_sub_l = self.create_subscription(Bool, '/lefteye_cmd', toggle_LED_l , 10)

def toggle_LED_r():
    ser.println("r");

def toggle_LED_l():
    ser.println("l");




rclpy.init()
ros_reader_node = RosReader()
rclpy.spin(ros_reader_node)
ros_reader_node.destroy_node()
rclpy.shutdown()
print("rclpy shut down")
