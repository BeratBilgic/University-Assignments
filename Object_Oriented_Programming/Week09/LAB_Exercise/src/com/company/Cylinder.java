package com.company;

public class Cylinder extends Shape3D{
    public Cylinder(double height, double radius) {
        super(height, radius);
    }

    @Override
    public double computeArea() {
        return (2*PI*radius*radius) + (2*PI*radius*height);
    }

    @Override
    public double computeVolume() {
        return PI*radius*radius*height;
    }

    @Override
    public String toString() {
        return "Cylinder --- Volume: " + computeVolume() + " Area: "+ computeArea();
    }
}
