cmake_minimum_required(VERSION 3.4.1)

set(JAVA_HOME "$ENV{JAVA_HOME}")
set(MAIN_JAVA_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/main/java")
set(MAIN_CPP_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp")
set(JNI_HEADER_FILE "${MAIN_CPP_SOURCE_DIR}/MushroomDetector.h")
set(JNI_SIGNATURE_FILE "${MAIN_CPP_SOURCE_DIR}/MushroomDetector_signature.txt")
# set(JAVA_H "\"${JAVA_HOME}/javah\"")
set(INTERFACE_FILE "${MAIN_JAVA_SOURCE_DIR}/com/example/christianaberger/cpptest/MushroomDetector.java")

set(OPENCV_SRC_DIR "$ENV{OPENCV_SOURCE_CODE_DIR}")
set(OPENCV_SDK_DIR "${OPENCV_SRC_DIR}/install/sdk/native")
set(OpenCV_DIR "${OPENCV_SDK_DIR}/jni")
set(OPEN_CV_LIB_DIR "${OPENCV_SDK_DIR}/libs/${ANDROID_NDK_ABI_NAME}")

set(STANDALONE_TOOLCHAIN "$ENV{STANDALONE_TOOLCHAIN}")
#set(CMAKE_FIND_ROOT_PATH ${CMAKE_FIND_ROOT_PATH} "${OPEN_CV_LIB_DIR}")
#list(APPEND CMAKE_PREFIX_PATH "libs/${ANDROID_NDK_ABI_NAME}")

find_package(OpenCV REQUIRED)

# Currently Adroid does not allow find_library outside of NDK root
# see: https://code.google.com/p/android/issues/detail?id=211927
# so we iterate the opencv libraries and add them to a LIBS variable one by one.
set(LIBS "")
foreach(libfile ${OpenCV_LIBS})
	find_library(TMP_${libfile} "${libfile}" HINTS "${OPEN_CV_LIB_DIR}" NO_CMAKE_FIND_ROOT_PATH)
	message(STATUS "found ${TMP_${libfile}} for ${libfile}")
	list(APPEND LIBS ${TMP_${libfile}})
	unset(sharedlib)
endforeach(libfile)

#message(STATUS "LIBS: ${LIBS}")

include_directories("${OpenCV_INCLUDE_DIRS}")

file (GLOB mushroom_SRC
	"src/main/cpp/*.cpp"
	"src/main/cpp/*.h"
)

add_library(mushroomlib SHARED
    ${mushroom_SRC}
    ${JNI_HEADER_FILE}
)

# execute the javah command and create the header file for the jni implementation:
add_custom_command(
	OUTPUT "${JNI_HEADER_FILE}"
	COMMAND ${CMAKE_COMMAND} -E env "PATH=${JAVA_HOME}/bin;$ENV{PATH}" javah -o ${JNI_HEADER_FILE} com.example.christianaberger.cpptest.MushroomDetector
	WORKING_DIRECTORY "${MAIN_JAVA_SOURCE_DIR}"
	DEPENDS	"${INTERFACE_FILE}"
)

link_directories("/Users/aberger/Downloads/opencv-3.2.0/install/sdk/native/libs/x86_64/")
find_library(log-lib log)

set(TOOLCHAIN_LIB64 ${STANDALONE_TOOLCHAIN}/x86_64-linux-android/lib64)
find_library(stl-lib gnustl_shared
	HINTS "${TOOLCHAIN_LIB64}" NO_CMAKE_FIND_ROOT_PATH
)
find_library(z-lib z)
message(STATUS "stlport lib: ${stl-lib}, toolchain: ${TOOLCHAIN_LIB64}")
target_link_libraries(mushroomlib ${log-lib} ${LIBS} ${stl-lib} ${z-lib})
