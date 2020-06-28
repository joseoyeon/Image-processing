#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <time.h>

using namespace std;
using namespace cv;

// 각 intensity 마다의 pixel 들을 count 해준다.
void imhist(Mat image, int histogram[]) {

	for (int i = 0; i < 256; i++) {
		histogram[i] = 0;
	}

	for (int y = 0; y < image.rows; y++)
		for (int x = 0; x < image.cols; x++)
			histogram[(int)image.at<uchar>(y, x)]++;
}


// sumHist 로 histgram 분포를 구한다 .
void sumhist(int histogram[], int sumhistogram[]) {
	sumhistogram[0] = histogram[0];
	for (int i = 1; i < 256; i++) {
		sumhistogram[i] = histogram[i] + sumhistogram[i - 1];
	}
}

//cdf 를 구한다.
void CDF(Mat image, int cdf[]) {
	double sumHist[256];

	int histogram[256];
	imhist(image, histogram); // 이미지 히스토그램 분포 확인

	int size = image.rows * image.cols;
	float alpha = 255.0 / size;

	int sumhistogram[256];
	sumhist(histogram, sumhistogram); // 시그마 nk

	for (int i = 0; i < 256; i++) {
		cdf[i] = cvRound((double)sumhistogram[i] * alpha);
		//시그마(nk/size) * 255 시그마 반올림해준다.
	}
}

Mat Matching(Mat image_input, Mat image_target) {
	int PI[256], PJ[256];
	CDF(image_input, PI);
	CDF(image_target, PJ);
	Mat image_output = image_input.clone();

	int LUT[256];
	for (int i = 0; i < 256; ++i) LUT[i] = 0; //Lookup Table 초기화
	for (int i = 0; i < 256; ++i) {
		for (int j = 1; j < 256; ++j) {
			if (PI[i] > PJ[j - 1] && PI[i] <= PJ[j]) LUT[i] = j; // 가까운 걸로 넣는다.
		}
	}
	for (int i = 0; i < image_input.rows; ++i) {
		for (int j = 0; j < image_input.cols; ++j) {
			image_output.at<uchar>(i, j) = LUT[image_input.at<uchar>(i, j)]; // 이미지 처리
		}
	}
	return image_output;
}


int main() {
	Mat image = imread("project02\\Phobos1.png", IMREAD_GRAYSCALE);
	Mat target_image = imread("project02\\Phobos2.png", IMREAD_GRAYSCALE);
	Mat imageDst;

	imageDst = Matching(image, target_image);

	// Display the original Image
	namedWindow("Original Image");
	imshow("Original Image", image);

	// Display the original Image
	namedWindow("Target Image");
	imshow("Target Image", target_image);

	// Display equilized image
	namedWindow("Histogram Matching Image");
	imshow("Histogram Matching Image", imageDst);

	imwrite("img_result.jpg", imageDst);
	waitKey();
	return 0;
}