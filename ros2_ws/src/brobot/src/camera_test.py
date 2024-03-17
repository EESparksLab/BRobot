#!/usr/bin/python3
import sys
import os
import rclpy
import time
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import threading 
import queue

class RosReader(Node):
    def __init__(self):
        super().__init__('Camera_test_node')
        self.l_cam_image_sub = self.create_subscription(Image,'/left_camera/image_raw',self.l_image_callback,10)
        self.bridge = CvBridge()
        self.flag = False
        self.cam_trigger = True

    #Ripped from the new aquisition code, will need edits for this test
    def l_image_callback(self,msg):
        if self.cam_trigger:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            file_location = "/spinPics/leftCam/"
            # if self.l_img_counter == 0:
            #     self.l_img_series_str = time.strftime("%Y%m%d_%H%M%S")
            #     os.mkdir(file_location + self.l_img_series_str, 0o777)
            #     os.chmod(file_location + self.l_img_series_str, 0o777)
            # filename = '%s%s/%d.jpg' % (file_location,self.l_img_series_str,self.l_img_counter)
            filename = "/image.jpg"
            cv2.imwrite(filename,cv_image)
            print("image saved at " + str(filename))
    


    def threaded_node_spin(self):
        print("camera node is spinning")
        rclpy.spin(self)

rclpy.init()
ros_reader_node = RosReader()
ros_thread = threading.Thread(target=ros_reader_node.threaded_node_spin)
ros_thread.start()
#we can put the test here
#We'll need a list of parameters and pass a filename to the camera code, that way we 
print("sending command to take a picture")
ros_reader_node.cam_trigger = True
time.sleep(5)

ros_reader_node.destroy_node()
rclpy.shutdown()
print("rclpy shut down")
