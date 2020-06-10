#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
void imageAdd(Mat& image1, Mat& image2, Mat& result);

int main()
{
    Mat img[20];// , output;
    img[0] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_00.png", IMREAD_COLOR);
    img[1] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_01.png", IMREAD_COLOR);
    img[2] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_02.png", IMREAD_COLOR);
    img[3] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_03.png", IMREAD_COLOR);
    img[4] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_04.png", IMREAD_COLOR);
    img[5] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_05.png", IMREAD_COLOR);
    img[6] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_06.png", IMREAD_COLOR);
    img[7] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_07.png", IMREAD_COLOR);
    img[8] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_08.png", IMREAD_COLOR);
    img[9] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_09.png", IMREAD_COLOR);
    img[10] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_10.png", IMREAD_COLOR);
    img[11] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_11.png", IMREAD_COLOR);
    img[12] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_12.png", IMREAD_COLOR);
    img[13] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_13.png", IMREAD_COLOR);
    img[14] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_14.png", IMREAD_COLOR);
    img[15] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_15.png", IMREAD_COLOR);
    img[16] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_16.png", IMREAD_COLOR);
    img[17] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_17.png", IMREAD_COLOR);
    img[18] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_18.png", IMREAD_COLOR);
    img[19] = imread("C:\\Users\\User\\Desktop\\visual_stdio\\Project1\\Project1\\lenna_noise\\lenna_gray_19.png", IMREAD_COLOR);

   int width = img[0].cols;
   int height = img[1].rows;

   Mat output(height, width, CV_8UC1);

   imageAdd(img[0],img[1], output);
   for(int i=2; i<20; i++)
       imageAdd(img[i], output, output);

    imshow("lenna_gray_00.png", img[0]);
    imshow("lenna_gray_01.png", img[1]);
    imshow("result", output);

    waitKey(0);
}

void imageAdd(Mat& image1, Mat& image2, Mat& result)
{
    int numOfLines = image1.rows; // number of lines in the image
    int numOfPixels = image1.cols; // number of pixels per a line
    result.create(image1.rows, image1.cols, image1.type());
    for (int r = 0; r < numOfLines; r++)
    {
        const uchar* data1_in = image1.ptr<uchar>(r);
        const uchar* data2_in = image2.ptr<uchar>(r);
        uchar* data_out = result.ptr<uchar>(r);
        for (int c = 0; c < numOfPixels*3+40; c++)
        {
            data_out[c] = saturate_cast<uchar>((data1_in[c] + data2_in[c])/2);
        }
    }
}