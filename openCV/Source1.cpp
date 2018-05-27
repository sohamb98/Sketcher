#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

double thresh;
double thresh_max = 225;
int thresh_slide = 127;
int ratio = 3;
int lowThreshold;
int const max_lowThreshold = 100;

int main() {
	Mat img;
	Mat img_grey;
	Mat threshimg;
	Mat edge;
	Mat draw;

	cout << "Welcome to the live image sketcher" << endl;
	cout << "To close the application after having fun press escape " << endl;
	
	double maxValue = 255;
	VideoCapture cam(0);
	while (1) {
		cam >> img;

		//convertin the frame to black and white 
		cvtColor(img, img_grey, CV_RGB2GRAY);
		namedWindow("camfeed", WINDOW_AUTOSIZE);
		imshow("camfeed", img);
		namedWindow("greyscale", WINDOW_AUTOSIZE);
		imshow("greyscale", img_grey);

		//Finding the canny edge
		namedWindow("CannyEdge", WINDOW_AUTOSIZE);
		createTrackbar("MinThreshold:", "CannyEdge", &lowThreshold, max_lowThreshold);

		blur(img_grey, edge, Size(3, 3));

		Canny(edge, edge, lowThreshold, lowThreshold*ratio, 3);
		edge.convertTo(draw, CV_8U);
		imshow("CannyEdge", draw);

        //thresholding to create a sketch
		threshold(edge, threshimg, thresh, maxValue, THRESH_BINARY_INV);
		namedWindow("Sketch", WINDOW_AUTOSIZE);

		char TrackbarName[50]="Threhold Slider";
		createTrackbar(TrackbarName, "Sketch", &thresh_slide, thresh_max);
		thresh = thresh_slide;

		imshow("Sketch", threshimg);

		
		if (waitKey(1)==27) {
			break;
		}
	}
	cam.release();
	destroyAllWindows();

	return 0;
}
