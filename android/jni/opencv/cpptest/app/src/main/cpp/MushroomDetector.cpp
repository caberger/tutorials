#include <jni.h>
#include <cstring>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "JniUtil.h"
#include "GrayScaler.h"
#include "Mushroom.h"
#include "MushroomDetector.h"

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
    Mushroom fromJavaObject(jobject);
    jobject asJavaObject(jclass, const Mushroom&);
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

    vector<char> bytes = util.getByteArrayField(obj, "color");
    int index = 0;
    for (vector<char>::iterator it = bytes.begin(); it != bytes.end(); it++) {
        mushroom.color[index++] = *it;
    }
    mushroom.mushRoomName = util.getStringField(obj, "mushroomName");
    mushroom.round = util.getBooleanField(obj, "round");
    return mushroom;
}
jobject MushroomMarshaller::asJavaObject(jclass clazz, const Mushroom& mushroom) {
    JniUtil util(env);

    jmethodID fid = env->GetMethodID(clazz, "<init>", "()V");
    jobject object = env->NewObject(clazz, fid);

    util.setStringField(object, "mushroomName", mushroom.mushRoomName.c_str());
    util.setBooleanField(object, "round", mushroom.round);
    static const int dims = 3;
    char bytes[dims];
    for(int i = 0; i < dims; i++) {
        bytes[i] = mushroom.color[i];
    }
    util.setBytearrayField(object, "color", bytes, dims);
    return object;
}
extern "C"
JNIEXPORT jobjectArray JNICALL Java_com_example_mushroom_identifier_MushroomDetector_computeSchwammerlType
        (JNIEnv *env, jobject mushroomDetector, jobjectArray templates, jstring filePath) {
    JniUtil util(env);
    MushroomMarshaller marshaller(env);

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
    vector<Mushroom> result = mushrooms; // for the demo we return the same data
    // in the real app call opencv detect method here that returns the result...

    jobjectArray objs = env->NewObjectArray(mushrooms.size(), elementClass, NULL);
    jsize index = 0;
    for(vector<Mushroom>::iterator it = result.begin(); it != result.end(); it++) {
        jobject object = marshaller.asJavaObject(elementClass, *it);
        env->SetObjectArrayElement(objs, index++, object);
    }

    // as a Demo that opencv works we use it to convert the image to grayscale...
    string path = util.toString(filePath);
    GrayScaler grayScaler;
    grayScaler.convertFiletoGray(util.toString(filePath).c_str());
    return objs;
}