# importing the module
import cv2
import imutils
from imutils import paths
import numpy as np
from PIL import Image
import PIL.ImageOps
from PIL import ImageGrab
import moviepy.editor as mp


def Average(lst):
     return sum(lst) / len(lst)

# reading the video
source = cv2.VideoCapture('CORN FIELD.MOV')
 
# running the loop
while True:
 
    # extracting the frames
    ret, image = source.read()
     
    # converting to gray-scale
    #gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    # Defining lower and upper bound HSV values
    lower1 = np.array([160, 10, 0])
    upper1 = np.array([170, 255, 255])
 
    lower2 = np.array([10, 10, 0])
    upper2 = np.array([20, 255, 255])
 
 
  
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
    #find the contours in the edged image and keep the largest one;
    #we'll assume that this is our target in the image
    cnts = cv2.findContours(mask.copy(), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    cnts = imutils.grab_contours(cnts)
    c = max(cnts, key = cv2.contourArea)
    # displaying the video
    #gray = mp.VideoFileClip(gray)
    #gray_resized = clip.resize(height=360)
    gray = cv2.resize(gray, (700, 600))
    gray = cv2.rotate(gray, cv2.ROTATE_180)
    
    indices = np.where(gray == [255])

    coordinates = indices[0]
    #print(coordinates)
    x_marker = int(Average(coordinates))
 
    #black
    cv2.line(gray, (x_marker,0), (x_marker,700), (5,255,100), 5)
    #gray
    cv2.line(gray, (350,0), (350,700), (120,255,100), 5)
    #cv2.imshow('Target', mask)
 
    if x_marker > 350:
        print('TURN RIGHT')
    else:
        print('TURN LEFT')
    #cv2.waitKey(0)
    
    
    cv2.imshow("Live", gray)
 
    # exiting the loop
    key = cv2.waitKey(1)
    if key == ord("q"):
        break
     
   