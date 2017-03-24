/*
 * Copyright (c) 2017 Aberger Software GmbH. All Rights Reserved.
 *               http://www.aberger.at
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may
 * obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */
#ifndef CPPTEST_JNIUTILS_H
#define CPPTEST_JNIUTILS_H

#include <string>
#include <vector>
#include <jni.h>

using namespace std;

/** Helper class to access JNI fields.
 */
class JniUtil {
public:
    JniUtil(JNIEnv *env) : env(env) {
    }
    string toString(jstring jniString);
    vector<char> getByteArrayField(jobject object, const char *name);
    void setBytearrayField(jobject, const char *name, char *bytes, int length);

    string getStringField(jobject object, const char *name);
    void setStringField(jobject object, const char *name, const char *value);

    bool getBooleanField(jobject object, const char *name);
    void setBooleanField(jobject, const char *name, bool value);
private:
    JNIEnv *env;
};

#endif //CPPTEST_JNIUTILS_H
