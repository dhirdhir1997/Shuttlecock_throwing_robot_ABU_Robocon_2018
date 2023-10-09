import cv2
import numpy as np
import time
import os

os.system("v4l2-ctl -d 1 -c white_balance_automatic=0")
os.system("v4l2-ctl -d 1 -c auto_exposure=1")
os.system("v4l2-ctl -d 1 -c gain_automatic=0")
os.system("v4l2-ctl -d 1 -c exposure=50")
os.system("v4l2-ctl -d 1 -c saturation=20")



cap = cv2.VideoCapture(1)

framecount = 0
prevMillis = 0
cv2.namedWindow('mask')

def nothing(x):
    pass

cap.set(cv2.CAP_PROP_FPS, 60)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)


def fpsCount():
    global prevMillis
    global framecount
    millis = int(round(time.time() * 1000))
    framecount += 1
    if millis - prevMillis > 1000:
        print(framecount)
        prevMillis = millis
        framecount = 0

cv2.createTrackbar('low h','mask',0,255,nothing)
cv2.createTrackbar('high h','mask',0,255,nothing)
cv2.createTrackbar('low s','mask',0,255,nothing)
cv2.createTrackbar('high s','mask',0,255,nothing)

while True:

    _, frame = cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)


    lowh = cv2.getTrackbarPos('low h', 'mask')
    highh = cv2.getTrackbarPos('high h', 'mask')
    lows = cv2.getTrackbarPos('low s', 'mask')
    highs = cv2.getTrackbarPos('high s', 'mask')
    lower_white = np.array([lowh,lows,0], dtype=np.uint8)
    upper_white = np.array([highh,highs,255], dtype=np.uint8)

    mask = cv2.inRange(hsv, lower_white, upper_white)

    res = cv2.bitwise_and(frame,frame, mask= mask)

    kernel = np.ones((13,13),np.uint8)
    closing = cv2.morphologyEx(res, cv2.MORPH_CLOSE, kernel)
    opening = cv2.morphologyEx(closing, cv2.MORPH_OPEN, kernel)

    gray= cv2.cvtColor(opening, cv2.COLOR_BGR2GRAY)

    ret,thresh1 = cv2.threshold(gray,60,255,cv2.THRESH_BINARY)


    fpsCount()
    cv2.line(frame, (0, 13), (320, 13), (255, 0, 0), 1)
    cv2.line(frame, (0, 227), (320, 227), (255, 0, 0), 1)
    cv2.line(frame, (307, 0), (307, 240), (255, 0, 0), 1)
    cv2.line(frame, (13, 0), (13, 240), (255, 0, 0), 1)
    cv2.imshow('frame',frame)
    cv2.imshow('mask',res)
    cv2.imshow('res',thresh1)
    cv2.imshow('close',closing)



    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
