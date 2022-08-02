# import the necessary packages
import imutils
from imutils import paths
import numpy as np
import cv2
from PIL import Image
import PIL.ImageOps 

# This code is broken into two main parts, the first section 'SECTION 1' deals with calibrating a camera using an object of 
# a known width and known distance formt he camera to find the camera's percieved focal length, variable 'focallength' Once this
# is known a continously same sized object can be located and the distance to that object can be estimated. The second section, 
#'SECTION 2' is where the code can take a new image, find the contours, using the previously calculated focal length, and draw a box around # the marker to produce the estimated distance, and then display it. The marker the code is looking for the nukbered stales the are next to # each corn plant nad are either yellow or bright orange.


# SECTION 1: CALIBRATION
# Resizing the image
def find_marker(image):
 
 # Convert Image to Image HSV
 image = cv2.resize(image, (700, 600))
 cv2.imshow('Test', image)
 cv2.waitKey(0)
 hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
  
 # Defining lower and upper bound HSV/RGB values
 # values for orange
 lower1 = np.array([6, 100, 20])
 upper1 = np.array([14, 200, 255])
 
 # values for yellow
 lower2 = np.array([24, 160, 20])
 upper2 = np.array([25, 255, 255])
 
  
 # Defining mask for detecting color
 lowermask = cv2.inRange(hsv, lower1, upper1)
 uppermask = cv2.inRange(hsv, lower2, upper2)
 
 #combine the two ranges to allow the code to look for both simultaneously 
 mask = lowermask + uppermask;
 #cv2.imshow('Mask', mask)
 
 # convert the image to grayscale, blur it, and detect edges
 ret,gray = cv2.threshold(mask,127,255,cv2.THRESH_BINARY)
 img = cv2.resize(image, (700, 600))
 gray = cv2.bitwise_not(gray)
 gray = cv2.GaussianBlur(mask, (5, 5), cv2.BORDER_DEFAULT)
 #cv2.imshow('gray', gray)
 edged = cv2.Canny(gray, 50, 200,L2gradient=True)
 
 # find the contours in the edged image and keep the largest one;
 # we'll assume that this is our marker in the image that we want
 cnts = cv2.findContours(mask.copy(), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
 cnts = imutils.grab_contours(cnts)
 c = max(cnts, key = cv2.contourArea)
 
 #next two lines allow you to see what the edged image appears as
 cv2.imshow('Outline', edged)
 cv2.waitKey(0) 
 # compute the bounding box of the of the paper region and return it
 return cv2.minAreaRect(c)


def distance_to_camera(knownWidth, focalLength, perWidth):
 # compute and return the distance from the maker to the camera
 return (knownWidth * focalLength) / perWidth

# initialize the known distance from the camera to the object, which
KNOWN_DISTANCE = 13
# initialize the known object width, which in this case, the piece of
# paper is 11 inches wide
KNOWN_WIDTH = 1.50
# load the first image that contains an object that is KNOWN TO BE 2 feet
# from our camera, then find the paper marker in the image, and initialize
# the focal length
image = cv2.imread("IMG_1105.jpg")
image = cv2.resize(image, (700, 600))
marker = find_marker(image)
#print(marker[1][0])
focalLength = (marker[1][0] * KNOWN_DISTANCE) / KNOWN_WIDTH
print(focalLength)


inches = distance_to_camera(KNOWN_WIDTH, focalLength, marker[1][0])
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
cv2.imshow("IMG_1105.jpg", image)
cv2.waitKey(0) 
print('Done')

# SECTION 2: FIND MARKER IN NEW IMAGE

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

# resize the images to display
img = cv2.resize(image, (700, 600))
cv2.imshow("IMG_1062.jpg", image)
cv2.waitKey(0) 
print('Done')