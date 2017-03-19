
rm -r build2
mkdir build2
pushd build2

SET CMAKE_PROG="%ANDROID_SDK%\cmake\3.6.3155560\bin\cmake.exe"
"C:\Android\sdk\cmake\3.6.3155560\bin\cmake.exe" -G"MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=%OPENCV_SOURCE_CODE_DIR%/install -DANDROID_ABI=armeabi-v7a -G"Android Gradle - Ninja" -DANDROID_PLATFORM=android-24 -DCMAKE_TOOLCHAIN_FILE=%NDK%\build\cmake\android.toolchain.cmake -DANDROID_NDK=%NDK% -DCMAKE_MAKE_PROGRAM=%ANDROID_SDK%\cmake\3.6.3155560\bin\ninja.exe ..
rem cmake --build . -- -j8
cmake --build . --target install -- -j8
popd
