# import the necessary packages
import imutils
from imutils import paths
import numpy as np
import cv2
from PIL import Image
import PIL.ImageOps
from PIL import ImageGrab

def Average(lst):
     return sum(lst) / len(lst)


def draw_marker(image):
 # Convert Image to Image HSV
 image = cv2.imread(image)
 image = cv2.resize(image, (700, 600))
 cv2.imshow('Test', image)
 hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
  
 # Defining lower and upper bound HSV values
 lower1 = np.array([0, 10, 0])
 upper1 = np.array([20, 255, 255])
 
 lower2 = np.array([120, 10, 0])
 upper2 = np.array([255, 255, 255])
 
  
 # Defining mask for detecting color
 lowermask = cv2.inRange(hsv, lower1, upper1)
 uppermask = cv2.inRange(hsv, lower2, upper2)
 mask = lowermask + uppermask;
 cv2.imshow('Mask', mask)
 
 ret,gray = cv2.threshold(mask,127,255,cv2.THRESH_BINARY)
 img = cv2.resize(image, (700, 600))
 gray = cv2.bitwise_not(gray)
 gray = cv2.GaussianBlur(mask, (5, 5), cv2.BORDER_DEFAULT)
 #cv2.imshow('gray', gray)
 edged = cv2.Canny(gray, 50, 200,L2gradient=True)
 #find the contours in the edged image and keep the largest one;
 #we'll assume that this is our target in the image
 cnts = cv2.findContours(mask.copy(), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
 cnts = imutils.grab_contours(cnts)
 c = max(cnts, key = cv2.contourArea)
 #next two redacted lines allow you to see what the edged image appears as
 cv2.imshow('Outline', edged)
 cv2.waitKey(0) 
 # compute the bounding box of the of the paper region and return it
 #return cv2.minAreaRect(c)
 # find x location of all white pixels
 
 indices = np.where(mask == [255])

 coordinates = indices[0]
 #print(coordinates)
 x_marker = int(Average(coordinates))
 
 #black
 cv2.line(mask, (x_marker,0), (x_marker,700), (5,255,100), 5)
 #gray
 cv2.line(mask, (350,0), (350,700), (120,255,100), 5)
 cv2.imshow('Target', mask)
 
 if x_marker > 350:
     print('TURN RIGHT')
 else:
     print('TURN LEFT')
 cv2.waitKey(0)

draw_marker("Bricks.jpg")