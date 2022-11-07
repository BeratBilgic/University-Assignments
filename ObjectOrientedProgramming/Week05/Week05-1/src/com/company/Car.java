package com.company;

public class Car {
    private Person owner;
    private String color;
    private String model;

    public Car(Person owner, String color, String model) {
        this.owner = owner;
        this.color = color;
        this.model = model;
    }

    public void changeOwner(Person person){
        this.owner = person;
    }

    public Person getOwner() {
        return owner;
    }
}
