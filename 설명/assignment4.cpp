#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
    const int mask[3][3] = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };

    const float fMaskTotalCoef = 1.f / 9.f;



    Mat inputImage = imread("Lenna_gray.png", IMREAD_GRAYSCALE);  // Read the file
    if (inputImage.empty())                              // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    Mat outputImage = inputImage.clone();

    CV_Assert(inputImage.depth() == CV_8U);
    int nChannels = inputImage.channels();
    int nRows = inputImage.rows;
    int nCols = inputImage.cols * nChannels;

    if (inputImage.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    for (int i = 1; i < inputImage.rows - 1; ++i)
    {
        for (int j = 1; j < inputImage.cols - 1; ++j)
        {
            int nSum = 0;
            for (int a = -1; a <= 1; ++a)
            {
                for (int b = -1; b <= 1; ++b)
                {
                    int intensity = inputImage.at<uchar>(i + a, j + b);
                    int coefficient = mask[a + 1][b + 1];

                    nSum += (intensity * coefficient);
                }
            }

            nSum *= fMaskTotalCoef;
            outputImage.at<uchar>(i, j) = uchar(nSum);
        }
    }

    namedWindow("input image", WINDOW_AUTOSIZE); // Create a window for display
    imshow("input image", inputImage);          // Show our image inside it.
    
    namedWindow("output image", WINDOW_AUTOSIZE); // Create a window for display
    imshow("output image", outputImage);          // Show our image inside it.
    waitKey(0);                                     // Wait for a keystroke in the window

    return 0;
}
