import cv2
img1=cv2.imread('image.png')
img2=cv2.imread('block.jpeg')
result=cv2.bitwise_or(img1,img2)

cv2.imshow(result)
cv2.waitKey(0)
cv2.destroyAllWindows()