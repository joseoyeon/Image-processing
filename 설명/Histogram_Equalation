
```c
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

void imhist(Mat image, int histogram[]){

    for (int i = 0; i < 256; i++){
        histogram[i] = 0;
    }

    for (int y = 0; y < image.rows; y++)
        for (int x = 0; x < image.cols; x++)
            histogram[(int)image.at<uchar>(y, x)]++;
}

void sumhist(int histogram[], int sumhistogram[]){
    sumhistogram[0] = histogram[0];
    for (int i = 1; i < 256; i++){
        sumhistogram[i] = histogram[i] + sumhistogram[i - 1];
    }
}

void matchHistogram(int srcHist[256], int refHist[256], int map[256]) {
    double cumSrc[256], cumRef[256];
    cumSrc[0] = srcHist[0];
    cumRef[0] = refHist[0];
    for (int i = 1; i < 256; i++) {
        cumSrc[0] = cumSrc[i - 1] + srcHist[i];
        cumRef[0] = cumRef[i - 1] + refHist[i];
    }
    for (int i = 0; i < 256; i ++ ) {
        cumSrc[i] /= cumSrc[255];
        cumRef[i] /= cumRef[255];
    }
    for (int i = 0; i < 256; i++) {
        int k = 255;
        while (cumRef[k] > cumSrc[i]) k--;
        map[i] = k < 0 ? 0 : k;
    }
}
int main(){
    Mat image = imread("project02\\Phobos1.png", IMREAD_GRAYSCALE);
    Mat target_image = imread("project02\\Phobos2.png", IMREAD_GRAYSCALE);

    int histogram[256];
    imhist(image, histogram); // 이미지 히스토그램 분포 확인

    int size = image.rows * image.cols;
    float alpha = 255.0 / size;
    
    int sumhistogram[256];
    sumhist(histogram, sumhistogram); // 시그마 nk

    // Scale the histogram
    int Sk[256];
    for (int i = 0; i < 256; i++){
        Sk[i] = cvRound((double)sumhistogram[i] * alpha); 
        //시그마(nk/size) * 255 시그마 반올림해준다.
    }

    // Generate the equlized image
    Mat new_image = image.clone();

    for (int y = 0; y < image.rows; y++)
        for (int x = 0; x < image.cols; x++)
            new_image.at<uchar>(y, x) = (Sk[image.at<uchar>(y, x)]);

    // Display the original Image
    namedWindow("Original Image");
    imshow("Original Image", image);

    // Display equilized image
    namedWindow("Equilized Image");
    imshow("Equilized Image", new_image);

    imwrite("img.jpg", image);
    imwrite("img_result.jpg", new_image);
    waitKey();
    return 0;
}
```
* input 이미지
![image](https://user-images.githubusercontent.com/46625602/85664371-20b1fe00-b6f5-11ea-8bae-0d34f2c06229.png)

* output 이미지
![image](https://user-images.githubusercontent.com/46625602/85664376-23145800-b6f5-11ea-93aa-d6037e3f7fd9.png)
