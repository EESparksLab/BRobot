mkdir -p ~/spinnaker_ws/src
cd spinnaker_ws/src
git clone https://github.com/neufieldrobotics/spinnaker_camera_driver.git
cd ~/spinnaker_ws/
catkin_make
source ~/spinnaker_ws/devel/setup.bash
