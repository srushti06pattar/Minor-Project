#converting rgb to grey image
import cv2
image= cv2.imread('block.jpeg')
grayscale= cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
cv2.imshow('original image',image)
cv2.imshow('grey image',grayscale)
cv2.waitKey(0)
cv2.destroyAllWindows()