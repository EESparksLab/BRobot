#!/usr/bin/python3
#Brobot imaging 
#designed around the flir camera ros node

#Libraries for our use-case
import sys
import os
import rclpy
import time
from rclpy.node import Node
from std_msgs.msg import Bool
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import threading 
import queue


class RosReader(Node):
    def __init__(self):
      super().__init__('brobot_acquisition_node')
      self.r_cam_sub = self.create_subscription(Bool, '/righteye_cmd', self.r_listener_callback , 10)
      self.l_cam_sub = self.create_subscription(Bool, '/lefteye_cmd', self.l_listener_callback , 10)
    ##Need to insert the camera raw image topic 
      self.bridge = CvBridge()
      self.r_acquisition_state = False
      self.r_img_series_str = 0
      self.r_img_counter = 0
      self.l_acquisition_state = False
      self.l_img_series_str = 0
      self.l_img_counter = 0
      self.r_cam_image_sub = self.create_subscription(Image,'/right_camera/image_raw',self.r_image_callback,10)
      self.l_cam_image_sub = self.create_subscription(Image,'/left_camera/image_raw',self.l_image_callback,10)  
    ##can probably add an action or another listener that can do the camera cleanup and exit if we so desire
    
    def r_image_callback(self,msg):
        if self.r_acquisition_state:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            #insert custom naming here
            file_location = "/spinPics/rightCam/"
            if self.r_img_counter == 0:
                self.r_img_series_str = time.strftime("%Y%m%d_%H%M%S")
                os.mkdir(file_location + self.r_img_series_str, 0o777)
                os.chmod(file_location + self.r_img_series_str, 0o777)
            filename = '%s%s/%d.jpg' % (file_location,self.r_img_series_str,self.r_img_counter)
            cv2.imwrite(filename,cv_image)
            self.r_img_counter += 1
            print("image saved at " + str(filename))
        else:
            self.r_img_counter = 0
    
    def l_image_callback(self,msg):
        if self.l_acquisition_state:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            #insert custom naming here
            file_location = "/spinPics/leftCam/"
            if self.l_img_counter == 0:
                self.l_img_series_str = time.strftime("%Y%m%d_%H%M%S")
                os.mkdir(file_location + self.l_img_series_str, 0o777)
                os.chmod(file_location + self.l_img_series_str, 0o777)
            filename = '%s%s/%d.jpg' % (file_location,self.l_img_series_str,self.l_img_counter)
            cv2.imwrite(filename,cv_image)
            self.l_img_counter += 1
            print("image saved at " + str(filename))
        else:
            self.l_img_counter = 0
    
    def r_listener_callback(self, msg):
        # global r_acquisition_state
        self.r_acquisition_state = msg.data
    def l_listener_callback(self, msg):
        # global l_acquisition_state
        self.l_acquisition_state = msg.data


rclpy.init()
ros_reader_node = RosReader()
rclpy.spin(ros_reader_node)
ros_reader_node.destroy_node()
rclpy.shutdown()
print("rclpy shut down")
