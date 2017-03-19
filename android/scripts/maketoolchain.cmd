REM Script to make a native toolchain. Please see android documentation for details.
SET ARCH=x86_64
mkdir ndk
pushd ndk
python %NDK%\build\tools\make_standalone_toolchain.py --arch %ARCH% --api 24 --stl=gnustl --unified-headers --install-dir %STANDALONE_TOOLCHAIN%
popd
