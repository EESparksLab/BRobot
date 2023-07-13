# syntax=docker/dockerfile:1
FROM osrf/ros:humble-desktop-full
RUN apt update && apt upgrade -y
RUN apt install -y --fix-missing \
    vim \
    usbutils \
    python3-pip
RUN pip install \
    pyserial \
    numpy \
    matplotlib \
    pillow

#TODO: automate the installation of the spinnaker SDK and Spinakker python module
