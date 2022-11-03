package com.company;

public class Main {

    public static void main(String[] args) {
        Person person1 = new Person("firstName1", "lastName1", 31,"job1");
        Car car1 = new Car(person1, "Blue", "Model1");
        car1.getOwner().showInfo();

        Person person2 = new Person("firstName2", "lastName2", 32,"job2");
        car1.changeOwner(person2);
        car1.getOwner().showInfo();
    }
}
