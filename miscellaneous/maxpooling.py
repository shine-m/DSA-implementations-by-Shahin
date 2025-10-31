from skimage import io, color,img_as_ubyte
from skimage.util import view_as_blocks
import numpy as np

def max_pooling(image_path, kernel_size=(9, 9)):
    # Read the image
    image = io.imread(image_path,)
    
    # Get image dimensions
    h, w,channel = image.shape
    k_h, k_w = kernel_size
    print(image.shape)
    # Ensure dimensions are divisible by kernel size
    new_h, new_w = h // k_h * k_h, w // k_w * k_w
    # image = image[:new_h, :new_w]
    new_image = image[:,:,2]
    
    # print(h,w,new_h,new_w)
    import matplotlib.pyplot as plt
    plt.imshow(new_image)
    # Perform max pooling using view_as_blocks
    blocks = view_as_blocks(new_image, block_shape=(k_h, k_w))
    pooled_image = blocks.max(axis=(2, 3))
    
    # return img_as_ubyte(pooled_image)

    plt.show        ()

def main():
    input_image = r"F:\mycoding\techdose\miscellaneous\input.jpg"  # Change this to your image path
    output_image = r"F:\mycoding\techdose\miscellaneous\pooled_output.jpg"
    
    pooled_result = max_pooling(input_image)
    
    # Save the output image
    # io.imsave(output_image, pooled_result)
    # print(f"Max pooled image saved as {output_image}")

if __name__ == "__main__":
    main()
