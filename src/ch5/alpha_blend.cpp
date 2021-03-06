#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char **argv)
{
    Mat src1 = imread(argv[1], 1);
    Mat src2 = imread(argv[2], 1);

    if (argc == 9 && !src1.empty() && !src2.empty())
    {
        int x = atoi(argv[3]);
        int y = atoi(argv[4]);
        int w = atoi(argv[5]);
        int h = atoi(argv[6]);
        double alpha = (double)atof(argv[7]);
        double beta = (double)atof(argv[8]);

        Mat roi1(src1, Rect(x, y, w, h));
        Mat roi2(src2, Rect(0, 0, w, h));

        addWeighted(roi1, alpha, roi2, beta, 0.0, roi1);

        namedWindow("Alpha Blend", 1);
        imshow("Alpha Blend", roi1);
        waitKey(0);
    }

    return 0;
}