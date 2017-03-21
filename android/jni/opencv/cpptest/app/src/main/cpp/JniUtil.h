//
// Created by Christian Aberger on 20.03.2017.
//

#ifndef CPPTEST_JNIUTILS_H
#define CPPTEST_JNIUTILS_H

#include <string>
#include <vector>
#include <jni.h>

using namespace std;

class JniUtil {
public:
    JniUtil(JNIEnv *env) : env(env) {
    }
    string toString(jstring jniString);
    vector<unsigned char> getByteArrayField(jobject object, const char *name);
    string getStringField(jobject object, const char *name);
    bool getBooleanField(jobject object, const char *name);
private:
    JNIEnv *env;
};

#endif //CPPTEST_JNIUTILS_H
