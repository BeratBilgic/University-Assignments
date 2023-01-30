package com.company;

public class Square extends Shape2D{
    public Square(double width) {
        super(width, width);
    }

    @Override
    public double computeArea() {
        return width * width;
    }

    @Override
    public String toString() {
        return "Square --- Width: " + width
                + " Area: " + computeArea();
    }
}
