package com.company;

public class Main {

    public static void main(String[] args) {
	    Circle c1 = new Circle(5);
        Circle c2 = new Circle(10);
        Circle c3 = new Circle(15);

        Circle[] circles = {c1, c2, c3};

        for (Circle c: circles) {
            System.out.println(c.computeArea());
        }
    }
}

/*
Lab Exercise-1: static keyword

Create a Circle class, where
declare a private constant  double variable PI has value of 3,141519
declare a private variable called double radius.
class constructor will have an argument to set radius.
declare a method called computeArea() to compute area of a circle object.
create 3 different circle instances, with radiuses 5, 10, 15.
print all the areas using a foreach loop.
 */
