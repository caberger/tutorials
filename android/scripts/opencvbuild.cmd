
SET OPENCV_DIR=%OPENCV_SOURCE_CODE_DIR%
SET PATH=%CMAKE_HOME%\bin;%PATH%

pushd %OPENCV_DIR%
pause
mkdir build
pushd build
cmake -G"MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE=%OPENCV_DIR%\platforms\android\android.toolchain.cmake -DCMAKE_MAKE_PROGRAM=%STANDALONE_TOOLCHAIN%\bin\make.exe ..
cmake --build . -- -j16

cmake --build . --target install

popd
popd
