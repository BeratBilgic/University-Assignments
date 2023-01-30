package com.company;

public class Cone extends Shape3D{
    public Cone(double height, double radius) {
        super(height, radius);
    }

    @Override
    public double computeArea() {
        double l = Math.sqrt(radius * radius + height * height);
        return (PI * radius * radius) + (PI * radius * l);
    }

    @Override
    public double computeVolume() {
        return (PI * radius * radius * height) / 3;
    }

    @Override
    public String toString() {
        return "Cone --- Volume: " + computeVolume() + " Area: "+ computeArea();
    }
}
