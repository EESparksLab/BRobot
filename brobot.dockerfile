# syntax=docker/dockerfile:1
FROM osrf/ros:humble-desktop-full
RUN apt update && apt upgrade -y
RUN apt install -y --fix-missing \
    vim \
    usbutils \
    python3-pip \
    udev \
    ros-humble-spinnaker-camera-driver \
    ros-humble-image-pipeline   \
    x11-apps 	

RUN pip install \
    pyserial \
    numpy \
    matplotlib \
    pillow \
    pandas
## TODO: cp the custom launch files for the camera driver into the proper directory
#/opt/ros/humble/share/spinnaker_camera_driver/launch

#following the steps to set up the ros camera driver
RUN echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="1e10", GROUP="flirimaging"' | sudo tee -a /etc/udev/rules.d/40-flir-spinnaker.rules
RUN echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="1724", GROUP="flirimaging"' | sudo tee -a /etc/udev/rules.d/40-flir-spinnaker.rules


#changes to add the ros workspace to the entrypoint 
RUN awk '/--/ { print; print "source /ros2_ws/install/setup.bash || true"; next}1' ros_entrypoint.sh > temp
RUN mv temp ros_entrypoint.sh
RUN chmod +x ros_entrypoint.sh