@echo off
SET ABI=x86_64
SET ANDROID_CMAKE=%ANDROID_SDK%\cmake\3.6.3155560
rm -r build
del /s /q build
mkdir build
pushd build

REM -DWITH_IPP=OFF -DWITH_OPENEXR=OFF

SET CMAKE_PROG="%ANDROID_CMAKE%\bin\cmake.exe"
%CMAKE_PROG% -G"MinGW Makefiles" -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=%OPENCV_SOURCE_CODE_DIR%/install -DANDROID_ABI=%ABI% -G"Android Gradle - Ninja" -DANDROID_PLATFORM=android-24 -DCMAKE_TOOLCHAIN_FILE=%NDK%\build\cmake\android.toolchain.cmake -DANDROID_NDK=%NDK% -DCMAKE_MAKE_PROGRAM=%ANDROID_SDK%\cmake\3.6.3155560\bin\ninja.exe ..
cmake --build . --target install -- -j4
popd
echo -------------------
echo Now please copy the shared libraries for your architecture from %OPENCV_SOURCE_CODE_DIR%/install/sdk/native/libs/%ABI% to ../src/main/jnilibs/%ABI% !!!!
echo--------------------