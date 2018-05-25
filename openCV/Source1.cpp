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
	VideoCapture cam(0);
	while (1) {
		cam >> img;
		cvtColor(img, img_grey, CV_RGB2GRAY);
		namedWindow("camfeed", WINDOW_AUTOSIZE);
		imshow("camfeed", img);
		namedWindow("greyscale", WINDOW_AUTOSIZE);
		imshow("greyscale", img_grey);
		if (waitKey(1)==27) {
			break;
		}
	}
	cam.release();
	destroyAllWindows();

	return 0;
}
