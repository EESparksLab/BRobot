import time
from roboclaw_3 import Roboclaw

#Windows comport name
#rc = Roboclaw("COM11",115200)
#Linux comport name
rc = Roboclaw("/dev/ttyACM0",115200)

rc.Open()
# address = bytes.fromhex('80')
address = 128 

while(1): 
    rc.ForwardM1(address,127)	#1/4 power forward
    rc.BackwardM2(address,127)	#1/4 power backward
    time.sleep(3)
	
    rc.BackwardM1(address,0)	#Stopped
    rc.ForwardM2(address,0)		#Stopped
    time.sleep(5)
    
    rc.DutyM1M2(address,127,127)
    time.sleep(3)
    # rc.BackwardM1(address,32)	#1/4 power backward
    # rc.ForwardM2(address,32)	#1/4 power forward
    # time.sleep(2)

    rc.BackwardM1(address,0)	#Stopped
    rc.ForwardM2(address,0)		#Stopped
    time.sleep(5)

    # m1duty = 16
    # m2duty = -16
    # rc.ForwardBackwardM1(address,64+m1duty)	#1/4 power forward
    # rc.ForwardBackwardM2(address,64+m2duty)	#1/4 power backward
    # time.sleep(2)
	
    # m1duty = -16
    # m2duty = 16
    # rc.ForwardBackwardM1(address,64+m1duty)	#1/4 power backward
    # rc.ForwardBackwardM2(address,64+m2duty)	#1/4 power forward
    # time.sleep(2)

    # rc.ForwardBackwardM1(address,64)	#Stopped
    # rc.ForwardBackwardM2(address,64)	#Stopped
    # time.sleep(2)
	
