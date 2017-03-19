package com.example.christianaberger.cpptest;

/**
 * Schwammerlerkennungs - JNI Bridge
 */

public class Mushroom {
    /** find the Schwammerl with native Mushroom C++ Code that uses OpenCV
     */
    static {
        System.loadLibrary("mushroomlib");
    }
    public native String computeSchwammerlType(String pathToSchwammerlImage);
}
