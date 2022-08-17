# importing the module
import cv2
import imutils
from imutils import paths
import numpy as np
from PIL import Image
import PIL.ImageOps
from PIL import ImageGrab
import moviepy.editor as mp


# 1. Open the device at the ID 0
cap = cv2.VideoCapture(0)

# 2. Open the camera video node to access the See3CAM_130

# Check if user selected camera is opened sucessfully
if not (cap.isOpened()):
 print ('The drugs are working great!')


# 3. Set the resolution of the camera by using OpenCV camera control properties
# To set the resolution
#cap.set(cv2.cv.CV_CAP_PROP_FRAME_WIDTH, 640)
#cap.set(cv2.cv.CV_CAP_PROP_FRAME_HEIGHT, 480)


# 4. Grab the frame continuously from the camera and show it in the preview window using the while loop. Enter ‘q’ key, to break the loop and exit the application
while(True):
 # Capture frame-by-frame
 ret, frame = cap.read()
 # Display the resulting frame
 cv2.imshow('preview',frame)
 # Waits for a user input to quit the application
 if cv2.waitKey(1) & 0xFF == ord('q'):
  break  


# 5. Release the camera, then close all of the imshow() windows.

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
    