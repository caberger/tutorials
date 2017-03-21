//
// Created by Christian Aberger on 20.03.2017.
//
#import "JniUtil.h"
using namespace std;

string JniUtil::toString(jstring jniString) {
    const char *nativeString = env->GetStringUTFChars(jniString, 0);
    string cvString = nativeString;
    env->ReleaseStringUTFChars(jniString, nativeString);
    return cvString;
}
vector<unsigned char> JniUtil::getByteArrayField(jobject obj, const char *name) {
    jclass klass = env->GetObjectClass(obj);
    jfieldID fid = env->GetFieldID(klass, "color", "[B");

    jobject colorObject = env->GetObjectField(obj, fid);
    jbyteArray& byteArray = reinterpret_cast<jbyteArray&>(colorObject);
    int length = env->GetArrayLength(byteArray);
    jbyte *color = env->GetByteArrayElements(byteArray, NULL);
    vector<unsigned char> bytes;
    for (int i = 0; i < length; i++) {
        bytes.push_back(color[i]);
    }
    env->ReleaseByteArrayElements(byteArray, color, 0);
    return bytes;
}
string JniUtil::getStringField(jobject obj, const char *name) {
    jclass klass = env->GetObjectClass(obj);
    jfieldID fid = env->GetFieldID(klass, "mushroomName", "Ljava/lang/String;");
    jstring stringObject = (jstring)env->GetObjectField(obj, fid);
    return stringObject ? toString(stringObject) : "";
}
bool JniUtil::getBooleanField(jobject object, const char *name) {
    jclass klass = env->GetObjectClass(object);
    jfieldID fid = env->GetFieldID(klass, name, "Z");
    jboolean val = env->GetBooleanField(object, fid);
    return val ? true : false;
}
