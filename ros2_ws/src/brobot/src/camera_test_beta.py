#!/usr/bin/python3
import sys
import os
import rclpy
import time
from rclpy.node import Node
from sensor_msgs.msg import Image
from flir_camera_msgs.msg import ImageMetaData
from flir_camera_msgs.msg import CameraControl
from cv_bridge import CvBridge
import cv2
import threading 
import queue

import numpy as np
import pandas as pd
import csv

class RosReader(Node):
    def __init__(self):
        super().__init__('Camera_test_node')
        self.l_cam_image_sub = self.create_subscription(Image,'/left_camera/image_raw',self.l_image_callback,10)
        self.meta_data_sub = self.create_subscription(ImageMetaData,'/left_camera/meta',self.meta_data_callback,10)
        self.cam_control_pub = self.create_publisher(CameraControl,'/exposure_control/control',10)
        self.bridge = CvBridge()
        self.flag = False
        self.cam_trigger = False
        self.file_name_str = ""
        self.meta_data_trigger = False
        self.current_expt = 0
        self.current_gain = 0

    #Ripped from the new aquisition code, wisource "/opt/ros/$ROS_DISTRO/setup.bash" --ll need edits for this test
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
            self.current_expt = data[0]
            self.current_gain = data[1]
            #save this meta data to a file
            filename = "/spinPics/camera_test/" + self.file_name_str
            with open(filename + ".csv", "w", newline="") as file:
                writer = csv.writer(file)
                # writer.writerow(["File Name", "Exposure Time", "Gain"])
                writer.writerow([self.file_name_str, data[0], data[1]])
                file.close()
            #print("meta data received")


    def threaded_node_spin(self):
        print("camera node is spinning")
        rclpy.spin(self)

rclpy.init()
ros_reader_node = RosReader()
ros_thread = threading.Thread(target=ros_reader_node.threaded_node_spin)
ros_thread.start()
apertures = [16,12,8,6,4,2.8,2,1.8]
working_distances = [9,10,12] ## inches

files = []
for N in apertures:
  files.append('/spinPics/camera_test/alpha_aperture_'+ str(N) + '.csv')

quantiles_k = []
quantiles_expt = []
for file in files:
  df = pd.read_csv(file,header=None)
  mean_expt = df[1].mean()
  std_dev_expt = df[1].std()
  mean_k = df[2].mean()
  std_dev_k = df[2].std()

  # print(f'Mean gain for {file}: {mean_k}')
  # print(f'Standard Deviation gain for {file}: {std_dev_k}')
  # print(f'Mean for exposure time{file}: {mean_expt}')
  # print(f'Standard Deviation for exposure time {file}: {std_dev_expt}')
  quantiles_expt.append([df[1].quantile(0.25),df[1].quantile(0.50),df[1].quantile(0.75)])
  quantiles_k.append([df[2].quantile(0.25),df[2].quantile(0.50),df[2].quantile(0.75)])
quantiles_k_matrix = np.array(quantiles_k)
quantiles_expt_matrix = np.array(quantiles_expt)
ros_reader_node.file_name_str = "null"
ros_reader_node.meta_data_trigger = True
for d in working_distances:
  input("Set to working distance " + str(d) + " inches" + " Press Enter to continue..." )
  counter = 0
  for N in apertures: 
    input("Set aperture to " + str(N) + " Press Enter to continue..." )
    for exp in quantiles_expt_matrix[counter]:
        for k in quantiles_k_matrix[counter]:
            msg = CameraControl()
            msg.exposure_time = int(exp)
            msg.gain = k
            ros_reader_node.cam_control_pub.publish(msg)
            time.sleep(1)
            ros_reader_node.file_name_str = "distance_"+ str(d) + "_aperture_" + str(N) + "_exp_" + str(exp) + "_gain_" + str(k)
            while(int(ros_reader_node.current_expt) != int(exp) or int(ros_reader_node.current_gain) != int(k)):
            	print(str(ros_reader_node.current_expt) + " != " + str(exp))
            	print(str(ros_reader_node.current_gain) + " != " + str(k))
            	pass
            ros_reader_node.cam_trigger = True
            while(ros_reader_node.cam_trigger):
                pass
    counter+=1
ros_reader_node.meta_data_trigger = False    

    


ros_reader_node.destroy_node()
rclpy.shutdown()
print("rclpy shut down")
