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
    jfieldID fid = env->GetFieldID(klass, name, "[B");
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
void JniUtil::setBytearrayField(jobject object, const char *name, char *bytes, int length) {
    jclass klass = env->GetObjectClass(object);

    jbyteArray byteArray = env->NewByteArray(length);
    env->SetByteArrayRegion(byteArray, 0, length, (jbyte *)bytes);

    jfieldID fid = env->GetFieldID(klass, name, "[B");
    env->SetObjectField(object, fid, byteArray);
}
string JniUtil::getStringField(jobject obj, const char *name) {
    jclass klass = env->GetObjectClass(obj);
    jfieldID fid = env->GetFieldID(klass, name, "Ljava/lang/String;");
    jstring stringObject = (jstring)env->GetObjectField(obj, fid);
    return stringObject ? toString(stringObject) : "";
}
void JniUtil::setStringField(jobject object, const char *name, const char *value) {
    jclass klass = env->GetObjectClass(object);
    jfieldID fieldId = env->GetFieldID(klass, name, "Ljava/lang/String;");
    jstring val = env->NewStringUTF(value);
    env->SetObjectField(object, fieldId, val);
}
bool JniUtil::getBooleanField(jobject object, const char *name) {
    jclass klass = env->GetObjectClass(object);
    jfieldID fid = env->GetFieldID(klass, name, "Z");
    jboolean val = env->GetBooleanField(object, fid);
    return val ? true : false;
}
void JniUtil::setBooleanField(jobject object, const char *name, bool value) {
    jclass klass = env->GetObjectClass(object);
    jfieldID fid = env->GetFieldID(klass, name, "Z");
    env->SetBooleanField(object, fid, value ? JNI_TRUE : JNI_FALSE);
}