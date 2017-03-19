#include <jni.h>
#include <cstring>
#include <iostream>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "logging.h"

using namespace cv;
using namespace std;

String toString(JNIEnv *env, jstring jniString) {
    const char *nativeString = env->GetStringUTFChars(jniString, 0);
    String cvString = nativeString;
    env->ReleaseStringUTFChars(jniString, nativeString);
    return cvString;
}
wstring towstring(JNIEnv* env, jstring string)  {
    wstring value;
    if (string != NULL) {
        const jchar *raw = env->GetStringChars(string, NULL);
        if (raw != NULL) {
            int len = env->GetStringLength(string);
            wchar_t* tmp = new wchar_t[len + 1];
            memset(tmp, 0, (len + 1) * sizeof(wchar_t));
            memcpy(tmp, raw, len * sizeof(wchar_t));
            value = tmp;
            delete[] tmp;
            env->ReleaseStringChars(string, raw);
        }
    }
    return value;
}
extern "C"
JNIEXPORT jstring JNICALL Java_com_example_christianaberger_cpptest_Mushroom_computeSchwammerlType
        (JNIEnv *env, jobject object, jstring name) {

    //wstring wstringVal = towstring(env, name);
    String fileName = toString(env, name);

    Mat gray = imread(fileName, CV_LOAD_IMAGE_GRAYSCALE); // use openCV
    blur(gray, gray, Size(3,3));
    int tresh = 100;
    imwrite(fileName, gray);

    string stdString = "also stl strings work!";
    LOGD("also stl strings work: %s", stdString.c_str());

    return env->NewStringUTF(fileName.c_str());
}