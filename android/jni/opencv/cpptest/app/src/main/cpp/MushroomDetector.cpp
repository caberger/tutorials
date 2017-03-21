#include <jni.h>
#include <cstring>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "JniUtil.h"
#include "GrayScaler.h"
#include "Mushroom.h"

using namespace cv;
using namespace std;

/** convert java Mushroom objects to C++ Mushroom objects.
 */
class MushroomMarshaller {
public:
/**
 * @param env the jni environment
 */
    MushroomMarshaller(JNIEnv *env) : env(env) {}
/**
 * for signatures see the constants see the output genterated from javap
 * @param obj the Mushroom java object
 * @return the converted c++ Mushroom object
 */
    Mushroom fromJavaObject(jobject obj);
private:
    JNIEnv *env;
};

/**
 * for signatures see the constants see the output genterated from javap
 * @param env the jni environment
 * @param obj the Mushroom java object
 * @return the converted c++ Mushroom object
 */
Mushroom MushroomMarshaller::fromJavaObject(jobject obj) {
    Mushroom mushroom;
    JniUtil util(env);

    vector<unsigned char> bytes = util.getByteArrayField(obj, "color");
    for (int i = 0; i < bytes.size(); i++) {
        mushroom.color[i] = bytes[i];
    }
    mushroom.mushRoomName = util.getStringField(obj, "mushroomName");
    mushroom.round = util.getBooleanField(obj, "round");
    return mushroom;
}
extern "C"
JNIEXPORT jobjectArray JNICALL Java_com_example_christianaberger_cpptest_MushroomDetector_computeSchwammerlType
        (JNIEnv *env, jobject mushroomDetector, jobjectArray templates, jstring filePath) {
    JniUtil util(env);
    MushroomMarshaller marshaller(env);

    string path = util.toString(filePath);
    int length = env->GetArrayLength(templates);
    vector<Mushroom> mushrooms;
    jclass elementClass = NULL;
    for (int i = 0; i < length; i++) {
        jobject templateElement = env->GetObjectArrayElement(templates, i);
        if (elementClass == NULL) {
            elementClass = env->GetObjectClass(templateElement);
        }
        Mushroom mushroom = marshaller.fromJavaObject(templateElement);
        mushrooms.push_back(mushroom);
    }
    jobjectArray objs = env->NewObjectArray(0, elementClass, NULL);

    GrayScaler grayScaler;
    grayScaler.convertFiletoGray(util.toString(filePath).c_str());
    return objs;
}