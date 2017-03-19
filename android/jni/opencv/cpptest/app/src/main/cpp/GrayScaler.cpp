
#include <cv.h>
#include <exception>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "GrayScaler.h"
#include "logging.h"

using namespace cv;
using namespace std;
const char *GrayScaler::convertFiletoGray(const char *fileName) {
    try {
        Mat gray = imread(fileName, CV_LOAD_IMAGE_GRAYSCALE); // use openCV
        blur(gray, gray, Size(3, 3));
        LOGD("writing %s", fileName);
        imwrite(fileName, gray);
    } catch( exception& e) {
        const char *err_msg = e.what();
        LOGE("failed: %s", err_msg);
    }
    return fileName;
}