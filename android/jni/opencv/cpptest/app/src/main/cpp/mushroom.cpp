#include <jni.h>
#include <cstring>
#include <iostream>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "logging.h"
#include "GrayScaler.h"

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

    const char *nativeString = env->GetStringUTFChars(name, NULL);
    String fileName = nativeString;

    GrayScaler grayScaler;
    grayScaler.convertFiletoGray(fileName.c_str());
    string stdString = "also stl strings work!";
    LOGD("also stl strings work: %s", stdString.c_str());
    fileName = "";
    env->ReleaseStringUTFChars(name, nativeString);
    return env->NewStringUTF(nativeString);
}