
#include "cv.h"
#include "highgui.h"

int main(int argc, char* argv[]) {
	IplImage* img;

	//take the 2nd element of arguments given in argument array as image
	img = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);

	//check given file is available or not
	if (!img) {

		printf("Could not load image file %s\n", argv[1]);

		return -1;
	}

	//assign image properties to defined variables
	int width = img->width;
	int height = img->height;
	int widthstep = img->widthStep;
	int channels = img->nChannels;

	printf("Width: %d\n", width);
	printf("Height: %d\n", height);
	printf("Width Step: %d\n", widthstep);//how many steps to be jumped to next row how much data in one row
	printf("No of channels: %d\n", channels);

	//going to access image data it is in uchar type
	uchar* data = (uchar*)img->imageData;

	int i = 100; //y axis
	int j = 100; //x axis

	//accessing one pixel
	int b = data[i * widthstep + j * channels];//for blue channel
	int g = data[i * widthstep + j * channels + 1];//for green channel num2
	int r = data[i * widthstep + j * channels + 2];//for red channel num3

	printf("Blue: %d\n", b);
	printf("Green: %d\n", g);
	printf("Red: %d\n", r);

	//try to convert to white color
	data[i * widthstep + j * channels] = 255;
	data[i * widthstep + j * channels + 1] = 255;
	data[i * widthstep + j * channels + 2] = 255;



	//converting 100*100 area to black color
	for (int a = 0; a <= 100; a++) {
		for (int b = 0; b <= 100; b++) {
			data[a * widthstep + b * channels] = 0;
			data[a * widthstep + b * channels + 1] = 0;
			data[a * widthstep + b * channels + 2] = 0;
		}

	}

	//create image in same size as our input image
	//1 means 1 channel
	IplImage* gray = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	//image data variable for newly created image
	uchar* graydata = (uchar*)gray->imageData;
	int grayWS = gray->widthStep;
	int grayCh = gray->nChannels;

	//converting into gray image mannually
	for (int a = 0; a < height; a++) {
		for (int b = 0; b < width; b++) {
			graydata[a * grayWS + b * grayCh] = data[a * widthstep + b * channels] * 0.1140 + data[a * widthstep + b * channels + 1] * 0.5870 + data[a * widthstep + b * channels + 2] * 0.2989;
		}
	}


	//convert gray scale image into black and white image
	for (int a = 0; a < height; a++) {
		for (int b = 0; b < width; b++) {
			if (graydata[a * grayWS + b * grayCh] > 150)
				graydata[a * grayWS + b * grayCh] = 255;
			else
				graydata[a * grayWS + b * grayCh] = 0;
		}
	}

	IplImage* invert = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
	uchar* dataI = (uchar*)invert->imageData;

	//convert BGR image into negative image (Invert BGR).
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			dataI[i * widthstep + j * channels] = 255 - data[i * widthstep + j * channels];
			dataI[i * widthstep + j * channels + 1] = 255 - data[i * widthstep + j * channels + 1];
			dataI[i * widthstep + j * channels + 2] = 255 - data[i * widthstep + j * channels + 2];
		}
	}

	//creating blue,red,green images
	IplImage* blue = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
	IplImage* green = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
	IplImage* red = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);

	uchar* dataB = (uchar*)blue->imageData;
	uchar* dataG = (uchar*)green->imageData;
	uchar* dataR = (uchar*)red->imageData;

	//converting color image to totally red,green,blue images
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			dataB[i * widthstep + j * channels] = data[i * widthstep + j * channels];
			dataB[i * widthstep + j * channels + 1] = 0;
			dataB[i * widthstep + j * channels + 2] = 0;
			dataG[i * widthstep + j * channels] = 0;
			dataG[i * widthstep + j * channels + 1] = data[i * widthstep + j * channels + 1];
			dataG[i * widthstep + j * channels + 2] = 0;
			dataR[i * widthstep + j * channels] = 0;
			dataR[i * widthstep + j * channels + 1] = 0;
			dataR[i * widthstep + j * channels + 2] = data[i * widthstep + j * channels + 2];
		}
	}

	//create image window
	cvNamedWindow("Image");
	//display image
	cvShowImage("Image", img);
	cvNamedWindow("Gray");
	cvShowImage("Gray", gray);
	cvNamedWindow("InvertImage");
	cvShowImage("InvertImage", invert);
	cvNamedWindow("Blue");
	cvShowImage("Blue", blue);
	cvNamedWindow("Green");
	cvShowImage("Green", green);
	cvNamedWindow("Red");
	cvShowImage("Red", red);
	cvWaitKey(0);
	cvDestroyAllWindows();
	
	return 0;

}