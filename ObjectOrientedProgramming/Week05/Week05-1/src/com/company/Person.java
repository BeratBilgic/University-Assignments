package com.company;

public class Person {
    private String firstName;
    private String lastName;
    private int age;
    private String job;

    public Person(String firstName, String lastName, int age, String job) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.job = job;
    }

    public void showInfo(){
        System.out.println("First Name: " + firstName + "\nLast Name: " + lastName + "\nAge: " + age + "\nJob: " + job
        + "\n");
    }
}

