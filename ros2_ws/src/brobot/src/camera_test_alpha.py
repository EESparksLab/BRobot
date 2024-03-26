#!/usr/bin/python3
import sys
import os
import rclpy
import time
from rclpy.node import Node
from sensor_msgs.msg import Image
from flir_camera_msgs.msg import ImageMetaData
from cv_bridge import CvBridge
import cv2
import threading 
import queue

import numpy as np
import csv

class RosReader(Node):
    def __init__(self):
        super().__init__('Camera_test_node')
        self.l_cam_image_sub = self.create_subscription(Image,'/left_camera/image_raw',self.l_image_callback,10)
        self.meta_data_sub = self.create_subscription(ImageMetaData,'/left_camera/meta',self.meta_data_callback,10)
        self.bridge = CvBridge()
        self.flag = False
        self.cam_trigger = False
        self.file_name_str = ""
        self.meta_data_trigger = False

    #Ripped from the new aquisition code
    def l_image_callback(self,msg):
        if self.cam_trigger:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            file_location = "/spinPics/camera_test/"
            # if self.l_img_counter == 0:
            #     self.l_img_series_str = time.strftime("%Y%m%d_%H%M%S")
            #     os.mkdir(file_location + self.l_img_series_str, 0o777)
            #     os.chmod(file_location + self.l_img_series_str, 0o777)
            # filename = '%s%s/%d.jpg' % (file_location,self.l_img_series_str,self.l_img_counter)
            filename = file_location + self.file_name_str + ".jpg"
            cv2.imwrite(filename,cv_image)
            self.cam_trigger = False
            print("image saved at " + str(filename))
    
    def meta_data_callback(self,msg):
        if self.meta_data_trigger: 
            data = [msg.exposure_time,msg.gain]
            #save this meta data to a file
            filename = "/spinPics/camera_test/" + self.file_name_str
            with open(filename + ".csv", "a", newline="\n") as file:
                writer = csv.writer(file)
                # writer.writerow(["File Name", "Exposure Time", "Gain"])
                writer.writerow([self.file_name_str, data[0], data[1]])
                file.close()
            print("meta data received")


    def threaded_node_spin(self):
        print("camera node is spinning")
        rclpy.spin(self)

rclpy.init()
ros_reader_node = RosReader()
ros_thread = threading.Thread(target=ros_reader_node.threaded_node_spin)
ros_thread.start()

apertures = [16,12,8,6,4,2.8,2,1.8]

for N in apertures:
    input("Set aperture to " + str(N) + " Press Enter to continue...\n")
    ros_reader_node.file_name_str = "alpha_aperture_" + str(N)
    ros_reader_node.meta_data_trigger = True
    time.sleep(30)
    ros_reader_node.meta_data_trigger = False 
     
ros_reader_node.destroy_node()
rclpy.shutdown()
print("rclpy shut down")
