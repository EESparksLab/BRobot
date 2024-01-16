######
#THIS PROGRAM DETECTS LINES IN SELECTED IMAGE AND RETURNS IMAGE WITH LINES DRAWN ON IT IN SPECIFIED FOLDER
######

import cv2
import numpy as np
import poly_point_isect as bot




img = cv2.imread('71.jpg')
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

kernel_size = 5
blur_gray = cv2.GaussianBlur(gray,(kernel_size, kernel_size),0)

#This sets the low and high threshlods for the canny, aka the edge detection. Examples of canny thresholds can be found in "flash_set_output" folder
low_threshold = 50
high_threshold = 150
edges = cv2.Canny(blur_gray, low_threshold, high_threshold)
#The line below creates a file for just the canny
#cv2.imwrite('71_canny.jpg', edges)

rho = 1  # distance resolution in pixels of the Hough grid
theta = np.pi / 180  # angular resolution in radians of the Hough grid
threshold = 15  # minimum number of votes (intersections in Hough grid cell)
min_line_length = 50  # minimum number of pixels making up a line
max_line_gap = 20  # maximum gap in pixels between connectable line segments
line_image = np.copy(img) * 0  # creating a blank to draw lines on

# Run Hough on edge detected image
# Output "lines" is an array containing endpoints of detected line segments
lines = cv2.HoughLinesP(edges, rho, theta, threshold, np.array([]),
                    min_line_length, max_line_gap)
points = []
for line in lines:
    for x1, y1, x2, y2 in line:
        points.append(((x1 + 0.0, y1 + 0.0), (x2 + 0.0, y2 + 0.0)))
        cv2.line(line_image, (x1, y1), (x2, y2), (255, 0, 0), 5)

lines_edges = cv2.addWeighted(img, 0.8, line_image, 1, 0)
#print(lines_edges.shape)
#cv2.imwrite('line_parking.png', lines_edges)

#Find intersections in lines found previously
#More info on poly_point_isect: https://github.com/ideasman42/isect_segments-bentley_ottmann
intersections = bot.isect_segments(points)
print(intersections)

for inter in intersections:
    a, b = inter
    for i in range(3):
        for j in range(3):
            lines_edges[int(b) + i, int(a) + j] = [0, 255, 0]

#Writes final output image with lines on it to file
cv2.imwrite('71_out.jpg', lines_edges)
