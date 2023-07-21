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
#COPY /brobot/src/utils /utilSoftware
#RUN echo "Y\n\n\n\n\n\n\n\n\nyes\nY\n\n" | /utilSoftware/spinnakerSRC/install_spinnaker.sh
#RUN pip install /utilSoftware/spinnakerPython/spinnaker_python-3.0.0.118-cp310-cp310-linux_x86_64.whl