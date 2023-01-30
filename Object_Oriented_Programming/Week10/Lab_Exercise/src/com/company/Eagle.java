package com.company;

public class Eagle extends Animal implements Flyable{
    @Override
    public void fly() {
        System.out.println("Eagle's fly method");
    }
}
