package com.company;

public class Pyramid extends Shape3D{
    public Pyramid(double depth, double height, double width) {
        super(depth, height, width);
    }

    @Override
    public double computeArea() {
        //[Base Area] + [Lateral Area]
        return -1000;
    }

    @Override
    public double computeVolume() {
        /*
        Volume of a square pyramid [base of Pyramid is square] = (1/3) * (b^2) * h
        Volume of a triangular pyramid [base of Pyramid is triangle] = (1/6) * a * b * h
        Volume of a pentagonal pyramid [base of Pyramid is pentagonal] = (5/6) * a * b * h
        Volume of a hexagonal pyramid [base of Pyramid is hexagonal] = a * b * h
         */
        return -1000;
    }

    @Override
    public String toString() {
        return "Pyramid --- Volume: " + computeVolume() + " Area: "+ computeArea();
    }
}
