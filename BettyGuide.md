# Brobot Betty User Guide
### Table of contents
| # | topic |
|---|-------|
| 1 | Control Scheme |
| 2 | Diagram of Tank |
| 3 | Process of Startup | 
| 4 | Operation Instructions |   

### Control Scheme
![BlueController](https://github.com/EESparksLab/BRobot/assets/78066794/c93e77f7-ab6e-44b8-a000-88a5c365376a)

Brobot Controls are still rather primitive! 
##### Startup the controller
Normally, the controller will already be set up with the Brain. Hit the power button in the center of the controller the indicator LED will *Blink White* then glow *Solid Blue* when connected to the computer.   

##### Pairing the device
TODO: add pictures     
In the event that you need to setup a controller with a Brobot Brain, follow these steps:     
1. Setup the Brobot Brain at a monitor and keyboard station as you will need to access the *Bluetooth menu*
2. If there are entries for "wireless controller", delete them, as they could be duplicates. 
3. Enter the controller into *pairing mode* by holding down the *share* button before and during powering on the controller.
4. The controller should show up as a device in the Bluetooth settings as "not setup", click connect
5. The process in complete when the indicator LED on the controller glows *Solid Blue*

### Diagram of the Tank

<img width="630" alt="BettyTankDiagram" src="https://github.com/EESparksLab/BRobot/assets/78066794/c1a38738-ae14-452f-b5d8-5cfebd76d749">

Betty is now closed with a top lid made of clear acrylic. This makes it easier to see the internals. A nice feature of this is that you can see the Roboclaw motor driver and its 3 feedback LEDS. 
When the Brobot program starts up, you will see the roboclaw blink 3 times, after this you will be able to controll the tank, as it recieves commands it will also blink and flash with the data coming in. 
If Brobot batteries are too low, the roboclaw indicator lights with flash 4 times periodically.    

If anything starts sparking or smoking you should head to safety and probably call the fire department.

### Process of Startup
WARNING: These instructions begin once the BRobot is in wheeled to its starting position and on the ground. Do not power on the BRobot before it is on the ground and ready to be run. 
It has already attempted suicide once before
1. Field Batteries     
  Brobot Betty uses an external battery pack to power the brain. Plug the connector into the wire coming out of the BettyTank.          
  <img width="546" alt="BettyBatteries" src="https://github.com/EESparksLab/BRobot/assets/78066794/99a02071-cfb8-4615-8ba6-270ab3b3ffe0">       
             
  <img width="602" alt="BettyBatteryCharging" src="https://github.com/EESparksLab/BRobot/assets/78066794/932dec43-64a3-48cc-ba14-73e696bdddc2">
  For charging, connect the aligator clips to one of the cells with the correct polarity. The charging block will indicate when the battery is charged.

2. Plug everything into the brain      
<img width="602" alt="BettyBrainBack" src="https://github.com/EESparksLab/BRobot/assets/78066794/456f4ca6-c6c0-4d5b-abd3-61847e21f65b">
<img width="506" alt="BettyBrainfront" src="https://github.com/EESparksLab/BRobot/assets/78066794/6540f197-b939-43d4-b570-031b114aeeb4">

3. Power on the brain
Using the power button on the front of the brain. The LED will glow *White*

4. Power on the controller
  See the controller section for more info
5. Power on the Tank
  <img width="647" alt="BettyPower charging" src="https://github.com/EESparksLab/BRobot/assets/78066794/a65d43b1-700b-4a84-9cbd-5828f80b155b">

6. Drive
   Try to keep even spacing between the lenses of the cameras and the subject!




