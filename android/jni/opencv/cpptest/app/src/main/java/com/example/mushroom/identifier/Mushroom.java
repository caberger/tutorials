package com.example.mushroom.identifier;

import java.util.Arrays;

public class Mushroom {
    public byte[] color = {0, 0, 0};
    public String mushroomName;
    public boolean round;

    @Override
    public String toString() {
        return "Mushroom{" +
                "color=" + Arrays.toString(color) +
                ", mushroomName='" + mushroomName + '\'' +
                ", round=" + round +
                '}';
    }
}
