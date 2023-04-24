import cv2
from skimage.metrics import structural_similarity as ssim

# Load the reference and test images
ref_image = cv2.imread('focus_reference_image.png')
test_image = cv2.imread('test_image.png')

# Convert the images to grayscale
ref_image_gray = cv2.cvtColor(ref_image, cv2.COLOR_BGR2GRAY)
test_image_gray = cv2.cvtColor(test_image, cv2.COLOR_BGR2GRAY)

# Compute the SSIM between the two images
ssim_value = ssim(ref_image_gray, test_image_gray)

# Print the SSIM value as a measure of focus quality
print(f"The SSIM value between the reference and test images is: {ssim_value:.3f}")
