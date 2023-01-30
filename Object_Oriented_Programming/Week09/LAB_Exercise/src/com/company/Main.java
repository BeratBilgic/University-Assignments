package com.company;

public class Main {

    public static void main(String[] args) {
        Square s1 = new Square(10);
        Rectangle r1 = new Rectangle(5,10);
        Circle c1 = new Circle(5);

        Shape2D[] shape2DS = {s1, r1, c1};

        Sphere sp1 = new Sphere(5,10);
        Cylinder cy1 = new Cylinder(10,5);
        Cone co1 = new Cone(10, 5);
        Pyramid py1 = new Pyramid(10, 10,10);

        Shape3D[] shape3DS = {sp1, cy1, co1, py1};

        for (Shape2D s :shape2DS) {
            System.out.println(s);
        }

        System.out.println();

        for (Shape3D s :shape3DS) {
            System.out.println(s);
        }
    }
}
