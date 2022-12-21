#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Import Statements
# import serial
import time
import rclpy as rospy
from rclpy.node import Node
import math
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool

def read_joy_data():
    rate = rospy.Rate(10)  # must be slower than the motor driver and pot update rates
    while not rospy.is_shutdown():  # CTRL+C ends ros node
        try:
           rospy.Subscriber("joy", String, ps4_handler)
        except:
            pass
        rate.sleep()

def ps4_handler(data):
    print(data.data)

def joystick_to_vw(x_joy, y_joy):
    ''' velocity (m/s), angular velocity (rad/s)
    # Define joystick motor out parameters '''
    ymin_in, xmin_in = -512,-512
    ymax_in, xmax_in = 512, 512
    #  ADJUST THESE VALUES TO CHANGE FORWARD VELOCITY (v) OR STEERING VELOCITY (w)
    #  Set min = -max
    ymin_out, xmin_out = -1.5, -1.0  #min v, min w
    ymax_out, xmax_out = 1.5, 1.0    #max v, max w

    M1_map = (y_joy -ymin_in) * (ymax_out-ymin_out) / (ymax_in-ymin_in) + ymin_out
    M2_map = (x_joy -xmin_in) * (xmax_out-xmin_out) / (xmax_in-xmin_in) + xmin_out
    v_constrained = constrain(M1_map, ymin_out, ymax_out)
    w_constrained = constrain(M2_map, xmin_out, xmax_out)
    return v_constrained, w_constrained


def constrain(val, min_val, max_val):
    if val < min_val:
        val = min_val
    elif val > max_val:
        val = max_val
    if abs(val) < 0.006:
        val = 0
    return val


def joy_publisher(x_cmd,y_cmd):
    print("Publishing joystick commands: " + str(x_cmd) + ',' + str(y_cmd))
    print("----------------------------")
    joy_msg = Twist()
    joy_msg.angular.z = x_cmd
    joy_msg.linear.x = y_cmd
    joy_pub.publish(joy_msg)


if __name__ == '__main__':
    # Find port in terminal: ls /dev
    # Data comes in as: int -512 to 512
    # ser = serial.Serial('/dev/ttyUSB0', 9600) # baud rate must match arduino code
    time.sleep(2)

    # Initialize ros node
    rospy.init()  # start the ros node pot_driver
    print('Waiting for joystick data...')

    # Setup ros publisher
    joy_pub = Node.create_publisher(Twist, 'joy_cmd', 10)
    trigger_pub = Node.create_publisher(Bool, 'data_trigger', 10)
    read_joy_data()
