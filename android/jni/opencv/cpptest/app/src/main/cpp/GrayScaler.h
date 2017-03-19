
#ifndef CPPTEST_GRAYSCALER_H
#define CPPTEST_GRAYSCALER_H
#include <cv.h>
using namespace cv;

class GrayScaler {
public:
    const char *convertFiletoGray(const char *fileName);
};


#endif //CPPTEST_GRAYSCALER_H
