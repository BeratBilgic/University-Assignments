package com.company;

public class Cat extends Animal implements Swimmable{
    @Override
    public void swim() {
        System.out.println("Cat's swim method");
    }
}
