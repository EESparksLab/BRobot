# import the necessary packages
import imutils
from imutils import paths
import numpy as np
import cv2
from PIL import Image
import PIL.ImageOps

def find_marker(image):
 # convert the image to grayscale, blur it, and detect edges
 # Resizing the image
 
 # Convert Image to Image HSV
 image = cv2.resize(image, (700, 600))
 cv2.imshow('Test', image)
 cv2.waitKey(0)
 hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
  
 # Defining lower and upper bound HSV values
 lower1 = np.array([6, 100, 20])
 upper1 = np.array([14, 200, 255])
 
 lower2 = np.array([24, 160, 20])
 upper2 = np.array([25, 255, 255])
 
  
 # Defining mask for detecting color
 lowermask = cv2.inRange(hsv, lower1, upper1)
 uppermask = cv2.inRange(hsv, lower2, upper2)
 mask = lowermask + uppermask;
 #cv2.imshow('Mask', mask)
 
 ret,gray = cv2.threshold(mask,127,255,cv2.THRESH_BINARY)
 img = cv2.resize(image, (700, 600))
 gray = cv2.bitwise_not(gray)
 gray = cv2.GaussianBlur(mask, (5, 5), cv2.BORDER_DEFAULT)
 #cv2.imshow('gray', gray)
 edged = cv2.Canny(gray, 50, 200,L2gradient=True)
 # find the contours in the edged image and keep the largest one;
 # we'll assume that this is our piece of paper in the image
 cnts = cv2.findContours(mask.copy(), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
 cnts = imutils.grab_contours(cnts)
 c = max(cnts, key = cv2.contourArea)
 #next two redacted lines allow you to see what the edged image appears as
 cv2.imshow('Outline', edged)
 cv2.waitKey(0) 
 # compute the bounding box of the of the paper region and return it
 return cv2.minAreaRect(c)

def draw_box(image):
 image = cv2.imread("IMG_1062.jpg")
 image = cv2.resize(image, (700, 600))
 marker = find_marker(image)
 inches = distance_to_camera(KNOWN_WIDTH, focalLength, marker[1][0])
 # draw a bounding box around the image and display it

 box = cv2.cv.BoxPoints(marker) if imutils.is_cv2() else cv2.boxPoints(marker)
 box = np.int0(box)
 print(box)
 #image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
 #image = cv2.bitwise_not(image)
 #ret,image = cv2.threshold(image,127,255,cv2.THRESH_BINARY)
 cv2.drawContours(image, [box], -1, (0, 255, 0), 2)
 cv2.putText(image, "%.2fft" % (inches / 12),
  (image.shape[1] - 200, image.shape[0] - 20), cv2.FONT_HERSHEY_SIMPLEX,
  2.0, (0, 255, 0), 3)
 img = cv2.resize(image, (700, 600))
 cv2.imshow("IMG_1062.jpg", image)
 cv2.waitKey(0) 
 print('Done')
