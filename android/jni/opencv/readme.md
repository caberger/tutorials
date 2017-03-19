Android NDK OpenCV/C++ Tutorial
===============================


Compile and use OpenCV in the Android Native Standalone Toolchain
------------------------------------------------------

1. install the latest version of Android Studio
2. in "Android SDK Tools" install CMake, NDK and LLDB
3. install Python
4. install CMake
6. download OpenCV [Source Code](https://github.com/opencv/opencv/releases) source code and unpack it to a folder.
5. read and understand [Android NDK standalone toolchain](https://developer.android.com/ndk/guides/standalone_toolchain.html) and adjust the parameters in the file ```maketoolchain.cmd```. 
4. adjust the paths in ```scripts\env.cmd``` to the paths on your computer.
4. open a command prompt by double klicking ```shell.cmd``` im the ```scripts``` folder, change in the command prompt to the scripts folder and run ```maketoolchain.cmd```this will create a ```ndk``` subfolder and a folder with the standalone toolchain.
13. This folder now contains the include files and libraries for the chosen ABI.
14. copy libgnustl_shared.so from this folder to src/main/jnilibs/%ABI%.
7. change to the subfolder ```app/opencvbuild``` and read the readme there to build opencv from the C++ source.

