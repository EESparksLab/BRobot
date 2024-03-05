# syntax=docker/dockerfile:1
FROM osrf/ros:humble-desktop-full
RUN apt update && apt upgrade -y
RUN apt install -y --fix-missing \
    vim \
    usbutils \
    python3-pip \
    udev \
    ros-humble-spinnaker-camera-driver
RUN pip install \
    pyserial \
    numpy \
    matplotlib \
    pillow

## TODO: cp the custom launch files for the camera driver into the proper directory
#/opt/ros/humble/share/spinnaker_camera_driver/launch

#following the steps to set up the ros camera driver
RUN echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="1e10", GROUP="flirimaging"' | sudo tee -a /etc/udev/rules.d/40-flir-spinnaker.rules
RUN echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="1724", GROUP="flirimaging"' | sudo tee -a /etc/udev/rules.d/40-flir-spinnaker.rules
