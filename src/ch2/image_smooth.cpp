#include <opencv2/opencv.hpp>

void smoothing_image(const cv::Mat & image) {
    // Create some windows to show the input
    // and output images in.
    cv::namedWindow("image-origin", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("image-smooth", cv::WINDOW_AUTOSIZE);

    // Create a window to show our input image
    //
    cv::imshow("image-origin", image);

    // Create an image to hold the smoothed output
    // 
    cv::Mat out;

    // Do the smoothing
    // (Note: Could use GaussianBlur(), blur() medianBlur() or bilateralFilter(). )
    //
    cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
    cv::GaussianBlur(out , out, cv::Size(5,5 ), 3, 3);

    cv::imshow("image-smooth", out);

    cv::waitKey(0);
}

int main(int argc, char **argv) {
    cv::Mat img = cv::imread(argv[1], -1);
    if (img.empty()) return -1;
    smoothing_image(img);
}
