import time
from roboclaw_3 import Roboclaw

#Windows comport name
#rc = Roboclaw("COM9",115200)
#Linux comport name
rc = Roboclaw("/dev/ttyACM0",115200)

def displayspeed():
	enc1 = rc.ReadEncM1(address)
	enc2 = rc.ReadEncM2(address)
	speed1 = rc.ReadSpeedM1(address)
	speed2 = rc.ReadSpeedM2(address)

	print("Encoder1:"),
	if(enc1[0]==1):
		print (enc1[1])
		print (format(enc1[2],'02x'))
	else:
		print ("failed")
	print ("Encoder2:")
	if(enc2[0]==1):
		print (enc2[1])
		print (format(enc2[2],'02x'))
	else:
		print ("failed ")
	print ("Speed1:")
	if(speed1[0]):
		print (speed1[1])
	else:
		print ("failed")
	print("Speed2:")
	if(speed2[0]):
		print (speed2[1])
	else:
		print ("failed ")

rc.Open()
address = 128

version = rc.ReadVersion(address)
error_causing_fuckface = rc.ReadMainBatteryVoltage(address)[1] / 10
if version[0]==False:
	print ("GETVERSION Failed")
else:
	print (repr(version[1]))

while(1):
	displayspeed()
