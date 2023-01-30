package com.company;

public class Rectangle extends Shape2D{
    public Rectangle(double height, double width) {
        super(height, width);
    }

    @Override
    public double computeArea() {
        return height * width;
    }

    @Override
    public String toString() {
        return "Rectangle --- Height: " + height
                + " Width: " + width
                + " Area: " + computeArea();
    }
}
