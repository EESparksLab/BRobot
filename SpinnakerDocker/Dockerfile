# This based off an auto generated Dockerfile for ros:ros-base
# generated from docker_images/create_ros_image.Dockerfile.em
FROM ros:kinetic-ros-base

# install bootstrap tools
RUN apt-get update && apt-get install --no-install-recommends -y \
	apt-utils		\
    build-essential \
    python-rosdep \
    python-rosinstall \
    python-vcstools \
    && rm -rf /var/lib/apt/lists/*

# bootstrap rosdep
RUN useradd -ms /bin/bash sparkslab
# RUN rm /etc/ros/rosdep/sources.list.d/20-default.list
# RUN rosdep init
# RUN runuser -l  sparkslab -c 'rosdep update'
# install ros packages
RUN apt-get update && apt-get install -y --no-install-recommends \
    ros-kinetic-ros-base \
	usbutils		\
	tree			\
	vim				\
	udev	   		\
	wget    		\
	libunwind-dev		\
	ros-kinetic-cv-bridge   \
	ros-kinetic-image-transport

RUN rm -rf /var/lib/apt/lists/*

#getting the Spinnaker SDK installed in the container
#the readme lists these dependencies
RUN sudo apt-get update && apt-get install -y --no-install-recommends \
	libavcodec-ffmpeg56		\
	libavformat-ffmpeg56	\
	libswscale-ffmpeg3		\
    libswresample-ffmpeg1	\
	libavutil-ffmpeg54		\
	libusb-1.0-0		


#get the ROS & SDK driver into the container
COPY ./src/spinnakerSDK /spinnakerSoftware/spinnakerSDK
COPY ./src/install_driver.sh /spinnakerSoftware/install_driver.sh
RUN chmod +x /spinnakerSoftware/install_driver.sh



