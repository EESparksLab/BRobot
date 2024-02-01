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

#TODO: automate the installation of the spinnaker SDK and Spinakker python module
COPY /utils /utilSoftware
# WORKDIR /utilSoftware/spinnakerSRC/
# #installing the spinnaker SDK; requires editing installer scripts to remove user interaction
# #as well as piping input to accept EULA
# RUN printf "Y\n\n\n\n\n\n\n\n\nyes\n" | ./install_spinnaker.sh
# RUN pip install /utilSoftware/spinnakerPython/spinnaker_python-3.0.0.118-cp310-cp310-linux_x86_64.whl


#following the steps to set up the ros camera driver
RUN echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="1e10", GROUP="flirimaging"' | sudo tee -a /etc/udev/rules.d/40-flir-spinnaker.rules
RUN echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="1724", GROUP="flirimaging"' | sudo tee -a /etc/udev/rules.d/40-flir-spinnaker.rules
