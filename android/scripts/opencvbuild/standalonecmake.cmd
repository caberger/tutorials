SET ABI=x86_64
rm -r build
mkdir build
pushd build

SET CMAKE_PROG="%ANDROID_SDK%\cmake\3.6.3155560\bin\cmake.exe"
"C:\Android\sdk\cmake\3.6.3155560\bin\cmake.exe" -G"MinGW Makefiles" -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=%OPENCV_SOURCE_CODE_DIR%/install -DANDROID_ABI=%ABI% -G"Android Gradle - Ninja" -DANDROID_PLATFORM=android-24 -DCMAKE_TOOLCHAIN_FILE=%NDK%\build\cmake\android.toolchain.cmake -DANDROID_NDK=%NDK% -DCMAKE_MAKE_PROGRAM=%ANDROID_SDK%\cmake\3.6.3155560\bin\ninja.exe ..
cmake --build . --target install -- -j4
popd
