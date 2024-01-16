import cv2
import numpy as np
import os
import poly_point_isect as bot
import detection as cn

def cannyFunc(image, output_name, low_threshold, high_threshold):
    img = cv2.imread(image)
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    kernel_size = 7
    blur_gray = cv2.GaussianBlur(gray,(kernel_size, kernel_size),0)
    #low_threshold = 150
    #high_threshold = 250
    edges = cv2.Canny(blur_gray, low_threshold, high_threshold, apertureSize = 3, L2gradient = True )
    cv2.imwrite(output_name, edges)
    return edges
    

cannyFunc('img_flash_set/0no_flash.jpg','flash_set_output/individuals/blur7_low200_high240_0no_flash.jpg',200,240)

###THESE LINES BELOW WERE MADE TO CREATE THE EDGE DETECTED IMAGES FOUND IN THE "flash_set_output" FOLDER

#for low in [30,50,70,100,130,160]:
#    for high in [200, 240,275,300,350]:
#        cannyFunc('img_flash_set/0no_flash.jpg','flash_set_output/canny_range_blur7/'+str(low)+'_'+str(high)+'_blur_0no_flash.jpg',low,high)


###Prototypes of calling the different functions offered by the "detection.py" library

#cn.cannyFunc('img_flash_set/'+file,'flash_set_output/canny_80_200/'+file)
#cn.houghLinesPFunc('img_flash_set/'+file,'flash_set_output/houghlinesp/'+file)
#cn.houghCircleRemove('img_flash_set/'+file,'flash_set_output/houghcirclesremove/'+'canny'+file,'flash_set_output/houghcirclesremove/'+'circles'+file,'flash_set_output/houghcirclesremove/'+'final'+file)
