import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool

class JoystickToTwistNode(Node):
    def __init__(self):
        super().__init__('joystick_to_twist_node')
        self.joy_sub = self.create_subscription(
            Joy, '/joy', self.joy_callback, 10)
        self.cmd_pub = self.create_publisher(Twist, 'tank_cmd', 10)
        self.r_cam_pub = self.create_publisher(Bool, 'righteye_cmd', 10)
        self.l_cam_pub = self.create_publisher(Bool, 'lefteye_cmd', 10)
        self.timer = self.create_timer(0.5,self.timer_callback)
        self.cam_triggers = [False, False]
    
    def timer_callback(self):
    	msg_r = Bool()
    	msg_l = Bool()
    	msg_l.data = self.cam_triggers[0]
    	msg_r.data = self.cam_triggers[1]
    	self.r_cam_pub.publish(msg_r)
    	self.l_cam_pub.publish(msg_l)

    def joy_callback(self, joy_msg):
        twist_msg = Twist()

        y_joy = joy_msg.axes[3] #right joystick y axis
        x_joy = joy_msg.axes[2] #right joystick x axis
        #converting Joystick input to tank control (taken from the old code)
        # Define joystick motor out parameters '''
        ymin_in, xmin_in = -1.0,-1.0
        ymax_in, xmax_in = 1.0, 1.0
        #  ADJUST THESE VALUES TO CHANGE FORWARD VELOCITY (v) OR STEERING VELOCITY (w)
        #  Set min = -max    ## no idea what this means
        ymin_out, xmin_out = -1.5, -1.0  #min v, min w
        ymax_out, xmax_out = 1.5, 1.0    #max v, max w
        M1_map = (y_joy -ymin_in) * (ymax_out-ymin_out) / (ymax_in-ymin_in) + ymin_out
        M2_map = (x_joy -xmin_in) * (xmax_out-xmin_out) / (xmax_in-xmin_in) + xmin_out

        twist_msg.angular.z = constrain(M1_map, ymin_out, ymax_out)
        twist_msg.linear.x = constrain(M2_map, xmin_out, xmax_out)
        self.cmd_pub.publish(twist_msg)

        #if the right face button is pressed; then toggle the right cam
        if joy_msg.buttons[1] == 1:
            self.cam_triggers[1] = not self.cam_triggers[1]
            print("Right camera is set to: ",self.cam_triggers[1])
        #if the left face button is pressed; then toggle the left cam
        if joy_msg.buttons[2] == 1:
            self.cam_triggers[0] = not self.cam_triggers[0]
            print("Left camera is set to: ",self.cam_triggers[0])

##also from the old code; I can't see why we need it but better safe than sorry
def constrain(val, min_val, max_val):
    if val < min_val:
        val = min_val
    elif val > max_val:
        val = max_val
    return val

# def camera_handler([right,left])
#     if

def main(args=None):
    rclpy.init(args=args)
    joystick_to_twist_node = JoystickToTwistNode()
    rclpy.spin(joystick_to_twist_node)
    joystick_to_twist_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
