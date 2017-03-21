package com.example.christianaberger.cpptest;

/**
 * Schwammerlerkennungs - JNI Bridge
 */

public class MushroomDetector {
    /** find the Schwammerl with native MushroomDetector C++ Code that uses OpenCV
     */
    static {
        System.loadLibrary("mushroomlib");
    }
    public native Mushroom[] computeSchwammerlType(Mushroom[] templates, String pathToSchwammerlImage);
}
