package com.company;

public class Circle extends Shape2D{
    public Circle(double radius) {
        super(radius);
    }

    @Override
    public double computeArea() {
        return radius * radius * PI;
    }

    @Override
    public String toString() {
        return "Circle --- Radius: " + radius
                + " Area: " + computeArea();
    }
}
