import cv2
import numpy as np
img =cv2.imread('block.jpeg',cv2.IMREAD_UNCHANGED)
resized_image=cv2.resize(img,(400,400))
imgB=resized_image[:,:,0]
imgG=resized_image[:,:,1]
imgR=resized_image[:,:,2]
# cv2.imshow('image',img)
imgN=np.hstack((imgB,imgG,imgR))
cv2.imshow('img',imgN)

cv2.waitKey(0)
cv2.destroyAllWindows()
