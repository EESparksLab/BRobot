#!/usr/bin/python

import math
import numpy as np
import time
import yaml
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
from std_msgs.msg import Float64
from std_msgs.msg import Int32

from utils.roboclaw_python.roboclaw_3 import Roboclaw
class RosReader(Node):
    def __init__(self):
      super().__init__('roboclaw_driver')
      self.joy_sub = self.create_subscription(Twist, '/tank_cmd', roboclaw_driver.joy_cmd_callback, 10)
      self.battery_pub = self.create_publisher(Float64, 'battery', 10)

class RoboclawDriver:
    def __init__(self):
        self.joy_cmd = Twist()
        self.time_interval = 0.05  # seconds between
        self.time_tic = time.perf_counter()

    def joy_cmd_callback(self, cmd):
        self.joy_cmd.linear.x = cmd.linear.x
        self.joy_cmd.angular.z = cmd.angular.z
        self.run_roboclaw()


    def run_roboclaw(self):
        try:
            M1_counts, M2_counts = self.get_counts()
            self.run_motors(M1_counts, M2_counts)  # Send commands to motors
            print("running motors with counts : ", M1_counts,M2_counts)
            msg_batt = Float64()
            msg_batt.data = float(rc.ReadMainBatteryVoltage(address)[1])/10
            self.battery_pub.publish(msg_batt) 
        except:
            print('Roboclaw power disconnected')
            try:
                if(rc.Open()):
                    print("roboclaw reconnected")
                else:
                    print("rc.open failed")
            except:
                print('reconnect failed, node crashing')
                rclpy.shutdown()



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
        max_counts = 650
        M1_duty = self.constrain(int(16000 * M1_counts/max_counts), -16000, 16000)
        M2_duty = self.constrain(int(-16000 * M2_counts/max_counts), -16000, 16000)
        rc.DutyM1M2(address, M1_duty, M2_duty)
        print('Running motors: ' + str(M1_duty) + ', ' + str(M2_duty))
        #rc.SpeedM1(address, int(M1_counts))  # M1 for linear movement
        #rc.SpeedM2(address, int(M2_counts))
        #print('Running motors: ' + str(M1_counts) + ', ' + str(M2_counts))


def stop_motors():
    print('Shutting down motors...')
    rc.SpeedM1(address, 0)
    rc.SpeedM2(address, 0)


def init_roboclaw():
    print('Current battery voltage: ' + str(float(rc.ReadMainBatteryVoltage(address)[1])/10))

    # address, P, I, D, QPPS
    # rc.SetM1VelocityPID(address, 5.00998, 0.4, 0.0, 5812) #rc.SetM1VelocityPID(address, 0.4, 0.0, 0.0, 545000) #0.7 seems okay with aligned shaft
    # rc.SetM2VelocityPID(address, 4.32053, 0.4, 0.0, 5625)
    time.sleep(1)
    print('M1 Velocity PID: ' + str(rc.ReadM1VelocityPID(address)))
    print('M2 Velocity PID: ' + str(rc.ReadM2VelocityPID(address)))

    # address, P, I, D, Imax, deadzone, min_cnts_limit, max_cnts_limit
    #rc.SetM1MaxCurrent(address, 30000) #milliamps, max running at 30 amps
    #rc.SetM2MaxCurrent(address, 30000) #milliamps
    #time.sleep(1)
    #print('M1 Position PID: ' + str(rc.ReadM1PositionPID(address)))
    print('M1 Max Current: ' + str(rc.ReadM1MaxCurrent(address)))
    print('M2 Max Current: ' + str(rc.ReadM2MaxCurrent(address)))

    # (address, S3, S4, S5) = (1, 9, 0, 58) S3 Estop (inverted), S5 limit both inverted
    # (address, S3, S4, S5) = (1, 9, 0, 9) S3 Estop (inverted 5V trigger), S5 Estop inverted
    #rc.SetPinFunctions(address,9,0,9)
    #print('Pin functions: ' + str(rc.ReadPinFunctions(address)))
    #time.sleep(1)




################################################################################


if __name__ == "__main__":
    # Initialize Motor Driver
    global rc, address
    rc = Roboclaw("/dev/ttyACM0", 115200)
    if(rc.Open()):
        address = 128
        init_roboclaw()
        time.sleep(2)
        print('Motor driver ready...')
    else:
        print("open() isn't working")
    roboclaw_driver = RoboclawDriver()

    rclpy.init()
    ros_reader_node = RosReader()
    rclpy.spin(ros_reader_node)
    ros_reader_node.destroy_node()
    rclpy.shutdown()
    stop_motors()  # on CTRL+C shutdown
