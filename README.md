# ImageProcessingBasics

IplImage Structure
- IplImage Structure came with C interface
- That structure is one dimensional array
- Need to allocate and de-allocate memory.
- Need to use header files (eg: “#include cv.h”, #include “highgui.h” etc...)
- Use IplImage pointer

1. First load BGR image using IplImage structure.
Steps:
• Declare a new IplImage pointer
• Load image using cvLoadImage() and Check image exist or not
• Display image window using cvNamedWindow() and cvShowImage()
• Wait image window until a keyboard button press using cvWaitKey()
• Destroy image window using cvDestroyWindow()
• Release image using cvReleaseImage()

2. Print height, width, width step and number of channels of the image using IplImage pointer

3. Then change the 100 x 100 pixel area of the image to black color and white color.

4. Replace the 100 x 100 pixel area of an image from 100 x 100 pixel area of another image. But i and j start from (100,100) pixel.

5. Convert BGR image to blank image.(black or white)

6. Convert BGR image to grayscale image. 
        IplImage* gray = cvCreateImage (cvSize (width, height), IPL_DEPTH_8U,1);
        Gray = 0.1140 * Blue + 0.5870 * Green +0.2989 * Red
7. Convert grayscale image to black and white (binary) image.

8. Then convert BGR image into negative image (Invert BGR).

9. Split BGR image into 3 channels. (Blue, Green, Red)

IplImage* blue = cvCreateImage (cvSize (width, height), IPL_DEPTH_8U,3); IplImage* green = cvCreateImage (cvSize (width, height), IPL_DEPTH_8U,3); IplImage* red = cvCreateImage (cvSize (width, height), IPL_DEPTH_8U,3
