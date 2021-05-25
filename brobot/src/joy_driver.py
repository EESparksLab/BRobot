#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Import Statements
import serial
import time
import rospy
import math
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool

def read_joy_data():
    rate = rospy.Rate(10)  # must be slower than the motor driver and pot update rates
    while not rospy.is_shutdown():  # CTRL+C ends ros node
        try:
            ser.flushInput()
            raw_joy_cmds = ser.readline().rstrip()
            if raw_joy_cmds.startswith('<') and raw_joy_cmds.endswith('>'):
                joy_cmds = raw_joy_cmds.strip('<').strip('>')
                print('Raw joystick inputs:' + str(joy_cmds))
                joy_list = joy_cmds.split(",")
                x_joy = int(joy_list[0])
                y_joy = int(joy_list[1])
                collect_data = int(joy_list[2])
                v, w = joystick_to_vw(y_joy, x_joy)
                joy_publisher(v, w)
                trigger_pub.publish(collect_data)
        except:
            pass
        rate.sleep()


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
    ser = serial.Serial('/dev/ttyUSB0', 9600) # baud rate must match arduino code
    time.sleep(2)

    # Initialize ros node
    rospy.init_node("joy_driver")  # start the ros node pot_driver
    print('Waiting for joystick data...')

    # Setup ros publisher
    joy_pub = rospy.Publisher('joy_cmd', Twist, queue_size=0)
    trigger_pub = rospy.Publisher('data_trigger', Bool, queue_size=0)
    read_joy_data()
