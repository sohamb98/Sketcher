#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat img;
	Mat img_grey;
	Mat threshimg;
	double thresh = 0;
	double maxValue = 255;
	VideoCapture cam(0);
	while (1) {
		cam >> img;
		cvtColor(img, img_grey, CV_RGB2GRAY);
		namedWindow("camfeed", WINDOW_AUTOSIZE);
		imshow("camfeed", img);
		namedWindow("greyscale", WINDOW_AUTOSIZE);
		imshow("greyscale", img_grey);
		threshold(img_grey, threshimg, thresh, maxValue, THRESH_BINARY);
		namedWindow("threshold", WINDOW_AUTOSIZE);
		imshow("threshold", threshimg);
		if (waitKey(1)==27) {
			break;
		}
	}
	cam.release();
	destroyAllWindows();

	return 0;
}
