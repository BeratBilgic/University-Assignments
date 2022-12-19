package com.company;

public class Duck extends Animal implements Moveable, Flyable, Swimmable{
    @Override
    public void fly() {
        System.out.println("Duck's fly method");
    }

    @Override
    public void move() {
        System.out.println("Duck's move method");

    }

    @Override
    public void swim() {
        System.out.println("Duck's swim method");
    }
}
