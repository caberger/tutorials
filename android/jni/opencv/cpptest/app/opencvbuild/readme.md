Build opencv/C++ for Android NDK
================================


* you have set the proper environment variables in ```/scripts/env.cmd``` before using the scripts here.
* you must have successfully installed the standalone native toolchain for your architecture, see maketoolchain.cmd in the scripts folder.

The ```buildopencv.cmd``` builds opencv from the source code with the given
Android Standalone Toolchain.


After the successful build you must copy the shared libraries to jnilibs, see 
the comment on the command shell after successful building.

