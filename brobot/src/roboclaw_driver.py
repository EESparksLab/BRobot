#!/usr/bin/python

import math
import numpy as np
import time
import yaml

import rospy
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
from std_msgs.msg import Float64
from std_msgs.msg import Int32

from utils.roboclaw_python.roboclaw import Roboclaw


class RoboclawDriver:
    def __init__(self):
        self.joy_cmd = Twist()
        self.time_interval = 0.05  # seconds between


    def joy_cmd_callback(self, cmd):
        self.joy_cmd.linear.x = cmd.linear.x
        self.joy_cmd.angular.z = cmd.angular.z


    def run_roboclaw(self, timer):
        try:
            M1_counts, M2_counts = self.get_counts()
            self.run_motors(M1_counts, M2_counts)  # Send commands to motors
        except:
            print('Roboclaw power disconnected')
            rospy.signal_shutdown('ERR: Power cutoff')



    def zero_cmd(self):
        self.cmd.linear.x = 0.0
        self.cmd.angular.z = 0.0


    ''' Velocity (m/s), Omega is angluar velocity'''
    def get_counts(self):
        l = 0.4 #length of robot in meters
        rwheel = .17/2 #radius of wheel in meters
        vright = ((self.joy_cmd.angular.z*l) + 2*self.joy_cmd.linear.x)/2
        vleft = 2*self.joy_cmd.linear.x - vright

        C = rwheel*2*math.pi

        lrev = vleft/C
        rrev = vright/C

        counts_per_rev = 1000

        M1_counts = rrev*counts_per_rev
        M2_counts = lrev*counts_per_rev        #may need to switch lrev and rrev

        return(M1_counts, M2_counts)

    def constrain(self, val, min_val, max_val):
        return min(max_val, max(min_val, val))

    ''' Send motor commands, M1 drive, M2 steer '''
    def run_motors(self, M1_counts, M2_counts):
        #max_counts = 2000
        #M1_duty = self.constrain(int(100 * M1_counts/max_counts), 0, 100)
        #M2_duty = self.constrain(int(100 * M2_counts/max_counts), 0, 100)
        #rc.DutyM1M2(address, M1_duty, M2_duty)
        #print('Running motors: ' + str(M1_duty) + ', ' + str(M2_duty))
        rc.SpeedM1(address, int(M1_counts))  # M1 for linear movement
        rc.SpeedM2(address, int(M2_counts))
        print('Running motors: ' + str(M1_counts) + ', ' + str(M2_counts))


def stop_motors():
    print('Shutting down motors...')
    rc.SpeedM1(address, 0)
    rc.SpeedM2(address, 0)


def init_roboclaw():
    print('Current battery voltage: ' + str(float(rc.ReadMainBatteryVoltage(address)[1])/10))

    # address, P, I, D, QPPS
    rc.SetM1VelocityPID(address, 5.00998, 0.4, 0.0, 5812) #rc.SetM1VelocityPID(address, 0.4, 0.0, 0.0, 545000) #0.7 seems okay with aligned shaft
    rc.SetM2VelocityPID(address, 4.32053, 0.4, 0.0, 5625)
    time.sleep(1)
    print('M1 Velocity PID: ' + str(rc.ReadM1VelocityPID(address)))
    print('M2 Velocity PID: ' + str(rc.ReadM2VelocityPID(address)))

    # address, P, I, D, Imax, deadzone, min_cnts_limit, max_cnts_limit
    rc.SetM1MaxCurrent(address, 2500) #milliamps, max running at 25 amps
    rc.SetM2MaxCurrent(address, 2500) #milliamps
    time.sleep(1)
    #print('M1 Position PID: ' + str(rc.ReadM1PositionPID(address)))
    print('M1 Max Current: ' + str(rc.ReadM1MaxCurrent(address)))
    print('M2 Max Current: ' + str(rc.ReadM2MaxCurrent(address)))

    # (address, S3, S4, S5) = (1, 9, 0, 58) S3 Estop (inverted), S5 limit both inverted
    # (address, S3, S4, S5) = (1, 9, 0, 9) S3 Estop (inverted 5V trigger), S5 Estop inverted
    rc.SetPinFunctions(address,9,0,9)
    print('Pin functions: ' + str(rc.ReadPinFunctions(address)))
    time.sleep(1)


def subscribe_to_topics():
    rospy.Timer(rospy.Duration(roboclaw_driver.time_interval), roboclaw_driver.run_roboclaw)
    rospy.Subscriber('joy_cmd', Twist, roboclaw_driver.joy_cmd_callback)
    rospy.spin()



################################################################################


if __name__ == "__main__":
    rospy.init_node('roboclaw_driver', anonymous=True)

    # Initialize Motor Driver
    global rc, address
    rc = Roboclaw("/dev/ttyACM0", 115200)
    rc.Open()
    address = 0x80
    init_roboclaw()
    time.sleep(2)
    print('Motor driver ready...')

    roboclaw_driver = RoboclawDriver()

    subscribe_to_topics()  # multithreaded loops forever
    stop_motors()  # on CTRL+C shutdown
