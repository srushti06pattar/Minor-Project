import cv2

# Load an image using 'imread'
image = cv2.imread('block.jpeg')
resized_image=cv2.resize(image,(100,100))
# Display the image using 'imshow'
cv2.imshow('Image', image)
cv2.imshow('resized image',resized_image)

# Wait for a key press and close the window
cv2.waitKey(0)
cv2.destroyAllWindows()
