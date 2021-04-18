import cv2
import serial
import os 
import time
import numpy as np
from random import randrange

ard= serial.Serial()
ard.port = "COM3"
ard.baudrate = 9600
ard.open()



trained_Frontface_data = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

webcam = cv2.VideoCapture(1)

while True:
    successful_frame_read, frame = webcam.read()

    grayscaled_img = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    face_coordinates = trained_Frontface_data.detectMultiScale(grayscaled_img, scaleFactor=1.05)
    print(face_coordinates)
    for (x, y, w, h) in face_coordinates:
        cv2.rectangle(frame, (x,y), (x+w, y+h), (0, 255, 0), 2)
        
        Xpos = x+(w/2)
        Ypos = y+(h/2)
        if Xpos >= 380:
            ard.write('L'.encode())
            time.sleep(0.01)       
        elif Xpos <= 260:          
            ard.write('R'.encode())
            time.sleep(0.01)       
        if Ypos > 300:
            ard.write('D'.encode())
            time.sleep(0.01)
        elif Ypos < 180:
            ard.write('U'.encode())
            time.sleep(0.01)

        break 

    
    cv2.imshow('Face Detector', frame)
    key = cv2.waitKey(1)

    if key==81 or key==113:
        break

webcam.release()


