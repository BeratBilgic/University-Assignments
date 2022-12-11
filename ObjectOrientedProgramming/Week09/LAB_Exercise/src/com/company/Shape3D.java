package com.company;

public abstract class Shape3D extends Shape2D{
    double depth;

    public Shape3D(double depth, double height, double width) {
        super(height, width);
        this.depth = depth;
    }

    public Shape3D(double height, double radius) {
        super(radius);
        this.height = height;
    }

    public abstract double computeVolume();
    public abstract String toString();
}
