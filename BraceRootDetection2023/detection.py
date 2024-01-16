#These functions perform edge detection, line detection, circle detection, and can remove circles from an image

import cv2
import numpy as np
import os
import poly_point_isect as bot

def cannyFunc(image, output_name):
    img = cv2.imread(image)
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    kernel_size = 5
    blur_gray = cv2.GaussianBlur(gray,(kernel_size, kernel_size),0)
    low_threshold = 150
    high_threshold = 250
    edges = cv2.Canny(blur_gray, low_threshold, high_threshold, apertureSize = 3, L2gradient = True )
    cv2.imwrite(output_name, edges)
    return edges


##HUGHES CIRCLE PART (ACTUALLY DRAWS CIRCLES IT IDENTIFIES)
def houghCircleFunc(image, output_name):
    imgc = cv2.imread(image,0)
    imgc = cv2.medianBlur(imgc,5)
    cimgc = cv2.cvtColor(imgc,cv2.COLOR_GRAY2BGR)
    circles=cv2.HoughCircles(imgc,cv2.HOUGH_GRADIENT,1,20,param1=50,param2=30,minRadius=3,maxRadius=50)
    circles = np.uint16(np.around(circles))
    for i in circles[0,:]:
        # draw the outer circle (Fills with black)
        cv2.circle(cimgc,(i[0],i[1]),i[2],(0,0,0),-1)
        # draw the center of the circle
        cv2.circle(cimgc,(i[0],i[1]),2,(0,0,0),3)
    cv2.imwrite(output_name,cimgc)

##REMOVES ANY CIRCLES IT FINDS BY MATCHING IT TO THE BLACK BACKROUND
def houghCircleRemove(image, output_canny,output_pre_final, output_final):
    edges = cannyFunc(image, output_canny)
    edges2 = edges
    imgc = cv2.imread(image,0)
    imgc = cv2.medianBlur(imgc,5)
    cimgc = cv2.cvtColor(imgc,cv2.COLOR_GRAY2BGR)
    circles=cv2.HoughCircles(imgc,cv2.HOUGH_GRADIENT,1,20,param1=50,param2=30,minRadius=5,maxRadius=70)
    circles = np.uint16(np.around(circles))
    for i in circles[0,:]:
        # draw the outer circle (Fills with black)
        cv2.circle(edges,(i[0],i[1]),i[2],(0,0,0),-1)
        # draw the center of the circle
        cv2.circle(edges,(i[0],i[1]),2,(0,0,0),3)
    #Writing Canny with circles removed from it
    cv2.imwrite(output_pre_final,edges)

    points = []
    #line_image = np.copy(img) * 0  # creating a blank to draw lines on
    lines = cv2.HoughLinesP(edges2, .4, np.pi / 270, 25, np.array([]),25, 20)
    for line in lines:
        for x1, y1, x2, y2 in line:
            points.append(((x1 + 0.0, y1 + 0.0), (x2 + 0.0, y2 + 0.0)))
            cv2.line(edges, (x1, y1), (x2, y2), (255, 0, 0), 5)
    #Writes final output of lines using canny with circles removed from it
    cv2.imwrite(output_final,edges)





##HUGHES LINES, STRAIGHT LINE DETECTION
def houghLinesPFunc(image, output_name):
    img = cv2.imread(image)
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    kernel_size = 5
    blur_gray = cv2.GaussianBlur(gray,(kernel_size, kernel_size),0)
    low_threshold = 150 #27
    high_threshold = 250 #75
    edges = cv2.Canny(blur_gray, low_threshold, high_threshold, apertureSize = 3, L2gradient = True )
    #cv2.imwrite('circletest/PICKME_canny3TRU_27_75.jpg', edges)

    rho = .4  # distance resolution in pixels of the Hough grid
    theta = np.pi / 90  # angular resolution in radians of the Hough grid
    threshold = 25  # minimum number of votes (intersections in Hough grid cell)
    min_line_length = 35  # minimum number of pixels making up a line
    max_line_gap = 20  # maximum gap in pixels between connectable line segments
    line_image = np.copy(img) * 0  # creating a blank to draw lines on

    # Run Hough on edge detected image
    # Output "lines" is an array containing endpoints of detected line segments
    lines = cv2.HoughLinesP(edges, rho, theta, threshold, np.array([]),
                        min_line_length, max_line_gap)
    #print(lines)
    points = []
    for line in lines:
        for x1, y1, x2, y2 in line:
            points.append(((x1 + 0.0, y1 + 0.0), (x2 + 0.0, y2 + 0.0)))
            cv2.line(line_image, (x1, y1), (x2, y2), (255, 0, 0), 5)

    lines_edges = cv2.addWeighted(img, 0.8, line_image, 1, 0)
    #print(lines_edges.shape)
    cv2.imwrite(output_name, lines_edges)
    
#houghCircleRemove('180.jpg', 'circletest08_16/canny180.jpg', 'circletest08_16/canny180Circle.jpg','circletest08_16/canny180CircleLine.jpg')
#cannyFunc('img_flash_set/IMG_3081.JPG', 'img_flash_set/IMG_3082g.JPG')

#for file in os.listdir(os.getcwd() + '/img_flash_set'):
#    print(file)
#    cannyFunc('img_flash_set/'+file,'flash_set_output/'+file)