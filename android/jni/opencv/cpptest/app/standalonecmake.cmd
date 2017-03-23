SET CMAKE_LOCATION=%ANDROID_SDK%\cmake\3.6.3155560\
SET CMAKE_BIN=%CMAKE_LOCATION%\bin
SET DEST=build\opencv
mkdir build
del /s /q %DEST%
rmdir /s /q %DEST
mkdir %DEST%
pushd %DEST%

setlocal
SET PATH=%CMAKE_BIN%;%PATH%
REM SET CMAKE_PROG="%ANDROID_SDK%\cmake\3.6.3155560\bin\cmake.exe"
cmake.exe -G"MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=%OPENCV_SOURCE_CODE_DIR%/install -DANDROID_ABI=x86_64 -G"Android Gradle - Ninja" -DANDROID_PLATFORM=android-24 -DCMAKE_TOOLCHAIN_FILE=%NDK%\build\cmake\android.toolchain.cmake -DANDROID_NDK=%NDK% -DCMAKE_MAKE_PROGRAM=ninja ..\..
cmake --build . -- -j8
endlocal
popd
xcopy /y %OPENCV_SOURCE_CODE_DIR%\install\sdk\native\libs\x86_64\*.so src\main\jnilibs\x86_64\
xcopy /y %STANDALONE_TOOLCHAIN%\x86_64-linux-android\lib64\libgnustl_shared.so src\main\jnilibs\x86_64\
pushd src\main\java

@echo off
echo ------------- signature -------------------
javap -s -cp build/intermediates/classes/debug/ com.example.christianaberger.cpptest.Mushroom
echo "-------------------------------------------"
popd