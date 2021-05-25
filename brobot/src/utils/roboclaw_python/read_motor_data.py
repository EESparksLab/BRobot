'''
Collect data on power consumption as the robot operates
'''

import rospy
import time
import math
from roboclaw import Roboclaw
from geometry_msgs.msg import Twist

def cmd_callback(cmd_sub):
    v = cmd_sub.linear.x
    w = cmd_sub.angular.z
    print('listening to cmd ' + str(v) + ',' +str(w))

    # Send commands to motors
    M1_counts, M2_counts = get_counts(v,w)
    run_motors(M1_counts, M2_counts)

def get_counts(v,w):
    ### velocity (m/s), angular velocity (rad/s) ###
    # Define motor params
    wheel_radius = 0.2921  # m
    enc_counts_per_output_rev = 500*130*6  # 500 crp motor, 130:1 gearbox ratio, 6:1 sprocket ratio
    m1enc = v/(2*math.pi*wheel_radius)*enc_counts_per_output_rev
    m2enc = (w/(2*math.pi))*enc_counts_per_output_rev
    return(m1enc, m2enc)

def run_motors(M1_counts, M2_counts):
    ### send motor commands M1 forward, M2 turning###
    rc = Roboclaw("/dev/ttyACM0",115200)
    rc.Open()
    address = 0x80
    print('running motors')
    rc.SpeedM1(address, int(M1_counts))  # M1 for linear movement
    rc.SpeedM2(address, int(M2_counts))  # M2 for turning
    display_speed()
    display_power_values()

def display_power_values():
    current = rc.ReadCurrents(address)
    voltage = rc.ReadMainBatteryVoltage(address)
    speed1 = rc.ReadSpeedM1(address)
    speed2 = rc.ReadSpeedM2(address)
    duty1 = rc.DutyM1(address)
    duty2 = rc.DutyM2(address)

    print(current)

    if(current[0]==1 and voltage[0]==1):
        print('M1 current: ' + str(current[1]) + ' Amps')
        print('M2 current: ' + str(current[2]) + ' Amps')
        print('Battery voltage: ' + str(voltage[1]) + ' Volts')
        print('M1 duty: ' + str(duty1) + ' SOMETHING')
        print('M2 duty: ' + str(duty2) + ' SOMETHING')
        print('M1 power: ' + str(0.001*current[1]*0.1*voltage[1]) +' Watts')
        print('M2 power: ' + str(0.001*current[2]*0.1*voltage[1]) +' Watts')

def display_speed():
	enc1 = rc.ReadEncM1(address)
	enc2 = rc.ReadEncM2(address)
	speed1 = rc.ReadSpeedM1(address)
	speed2 = rc.ReadSpeedM2(address)

	print("Encoder1:"),
	if(enc1[0]==1):
		print enc1[1],
		print format(enc1[2],'02x'),
	else:
		print "failed",
	print "Encoder2:",
	if(enc2[0]==1):
		print enc2[1],
		print format(enc2[2],'02x'),
	else:
		print "failed " ,
	print "Speed1:",
	if(speed1[0]):
		print speed1[1],
	else:
		print "failed",
	print("Speed2:"),
	if(speed2[0]):
		print speed2[1]
	else:
		print "failed "


def stop_motors():
    print('shutting down motors...')
    rc = Roboclaw("/dev/ttyACM0",115200)
    rc.Open()
    address = 0x80
    rc.SpeedM1(address, 0)  # M1 for linear movement
    rc.SpeedM2(address, 0)  # M2 for turning


if __name__ == '__main__':

    global rc, address
    rc = Roboclaw("/dev/ttyACM0",115200)
    rc.Open()
    address = 0x80

    rospy.init_node('motor_driver', anonymous=True)
    rospy.on_shutdown(stop_motors)

    while not rospy.is_shutdown():
        rospy.Subscriber('motor_cmds', Twist, cmd_callback)
        rospy.spin()

  
