package com.company;

public abstract class Shape2D {
    final double PI = 3.14;
    double height;
    double width;
    double radius;

    public Shape2D(double height, double width) {
        this.height = height;
        this.width = width;
    }

    public Shape2D(double radius) {
        this.radius = radius;
    }


    public abstract double computeArea();
    public abstract String toString();
}
