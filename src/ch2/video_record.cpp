#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char *argv[])
{
    namedWindow("Example2_11", WINDOW_AUTOSIZE);
    namedWindow("Log_Polar", WINDOW_AUTOSIZE);

    VideoCapture capture(argv[1]);

    double fps = capture.get(CAP_PROP_FPS);
    Size size(
        (int)capture.get(CAP_PROP_FRAME_WIDTH),
        (int)capture.get(CAP_PROP_FRAME_HEIGHT));

    VideoWriter writer;
    writer.open(argv[2], VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

    Mat logpolar_frame, bgr_frame;
    for (;;)
    {
        capture >> bgr_frame;
        if (bgr_frame.empty())
            break;

        imshow("Example2_11", bgr_frame);

        logPolar(
            bgr_frame,
            logpolar_frame,
            Point2f(
                bgr_frame.cols / 2,
                bgr_frame.rows / 2),
            40,
            WARP_FILL_OUTLIERS);

        imshow("Log_Polar", logpolar_frame);
        writer << logpolar_frame;

        char c = waitKey(10);
        if (c == 28)
            break;
    }

    capture.release();
}