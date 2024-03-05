# BRobot

Brace root-robot (known as BRobot) is a project that resulted from a 2018 CAT EPoC grant. 
This grant proposed the development of a sub-canopy robot that could capture hard to reach data in corn fields. 

The code for this project can be found in the ros2_ws/src/brobot

Data processing of images occurs through the Root Tagging GUI in an associated repository.


The BRobot methods were released in:
Stager A, Tanner HG and Sparks EE. “Design and Construction of Unmanned Ground Vehicles for Sub-Canopy Plant Phenotyping” arXiv, 2019. 
http://arxiv.org/abs/1903.10608

The BRobot was used in a publication:
Hostetler AN, Erndwein L, Reneau JW, Cantera W, Stager A, Tanner HG, Cook DD and Sparks EE. 
“Brace root phenotypes predict root lodging susceptibility and the contribution to anchorage in maize” bioRxiv, 2021.
https://doi.org/10.1101/2021.05.12.443923

A user video can be found on our lab YouTube Channel:
https://youtu.be/CtgOI4ltgGw




# Installing the Software

## Requirements 
 - Linux on x86, running a modern kernel
 - Docker [(instructions to install)](https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository)

## Instructions
Pull down the Repo and open a terminal in the root     
run this command: 
`docker build -t brobot:latest -f ./brobot.dockerfile .`

This command will use the file `brobot.dockerfile` to build a container that has all of brobots dependencies and software installed within.

you can now spin up the brobot docker image using this command      
`./brobot_base_generic`   
This script will open up a shell inside the container as well as including the proper arguments to access hardware components and save files

Run this set of commands to spin up the brobot
```bash
source ros2_ws/install/setup.bash
ros2 launch brobot brobot.launch.py
```
The first command is to add the brobot package to the path of the ros2 install. The second command is to use the ROS2 launch system to start each of brobot node programs. 

Here are a list of nodes that are launched, please note that if the hardware component is not plugged in before you enter the container, the nodes (marked with *) will crash. 
- Roboclaw Driver*     
- Spinnaker Camera modules left and right* 
- control panel* 
- Image Acquisition Node
- Joy Driver node 
- Joy Node

Images collected by the brobot can be found at `ros2_ws/src/brobot/src/spinPics`

# Developers adding software
### Editing the docker container
In the event that we need to add a package, file or other changes to the environment. You would need to edit the dockerfile with the proper commands

```dockerfile
# syntax=docker/dockerfile:1
FROM osrf/ros:humble-desktop-full
RUN apt update && apt upgrade -y
#append required packages from the apt repo here
RUN apt install -y --fix-missing \
    vim \
    usbutils \
    python3-pip \
    udev \
    ros-humble-spinnaker-camera-driver
#append required python packages here
RUN pip install \
    pyserial \
    numpy \
    matplotlib \
    pillow

#append environment modifiers and one-off commands here. Use proper comments: Why are you putting this here?


#following the steps to set up the ros camera driver
RUN echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="1e10", GROUP="flirimaging"' | sudo tee -a /etc/udev/rules.d/40-flir-spinnaker.rules
RUN echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="1724", GROUP="flirimaging"' | sudo tee -a /etc/udev/rules.d/40-flir-spinnaker.rules
```
## Editing the ROS2 package
For simple edits to the existing nodes you can simply edit their source code which can be found at this relative path from the base of the repository
`ros2_ws/src/brobot/src`

## Adding a Node
For example: You have a python script that attempts to index the images taken based on if a brace root is detected. You have no hardware that needs to be added and all your required python packages are already installed in the docker container.

### Step 1: add to the brobot src directory
In `ros2_ws/src/brobot/src` you will add your python script. Be sure to add execute permissions and a shebang to your file. 

### Step 2: Add to launch file
`ros2_ws/src/brobot/launch/brobot.launch.py`     
2 statements must be added to this file and they look like this:
```python
#define your node object
my_new_node = Node(package = 'brobot',
                executable='my_new_node.py',
                name='my_new_node')
#add the object to the launch description 
ld.add_action(my_new_node)
```
### Step 3: Rebuild the ROS2 package
Navigate to /ros2_ws in the docker container and run the commands
```bash
colcon build
source /install/setup.bash
```

Now when you run `ros2 launch brobot brobot.launch.py` your new node will be running along with all the others. 

# Developers adding hardware
For adding the software packages or handler scripts, refer to the guide above.

For example: Say you have a Inertial measurement unit and you wish to use it to track the brobots movements. You have a python script that logs this data and you have added it as a node using the above guide. The IMU connects through USB and you can see that it connects to the port `/dev/ttyACM2`
### Step 1: Add the device to brobot_base_generic
```bash
#!/bin/bash
SRCDIR=$(pwd)/ros2_ws/
docker run -it \
    -v /var/run/dbus/:/var/run/dbus \
    -v $SRCDIR:/ros2_ws \
    -v $SRCDIR/src/brobot/src/spinPics:/spinPics \
    --device=/dev/ttyACM0   \
    --device=/dev/ttyACM1   \
    --device=/dev/ttyACM2   \ ##Added here
    --privileged \
    brobot $@
```
We use the `--device` tag in the `docker run` command to allow the device easy access to the container. 

Note that the other entries are for the roboclaw on `ttyACM0` and the control panel on `ttyACM1`
we might need start writing udev rules if you can't get them in the right order. 

Now your node program should be able to use your new hardware. 
      







