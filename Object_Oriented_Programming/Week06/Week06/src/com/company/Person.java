/*
Lab exercise : Calling a Constructor From a Constructor

Create a class called Person where, id, firstName, lastName, and age attributes are declared.
Create four constructors
In first, set all attributes;
In the second, set only first and last names, automatically increment id and  set age to zero;
In the third, only set id, and set rest to default values;
Int the last only increment id, set the rest to default values.
 */

package com.company;

public class Person {
    private static int idCount;
    private final int id;
    private String firstName;
    private String lastName;
    private int age;

    public Person (int id, String firstName, String lastName, int age) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
    }

    public Person(String firstName, String lastName) {
        this(++idCount, firstName, lastName, 0);
        idCount = idCount++;
    }

    public Person(int id) {
        this(id,"default firstName","default lastName",-1);
    }

    public Person() {
        this(++idCount,"default firstName","default lastName",-1);
        idCount = idCount++;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getAge() {
        return age;
    }

    public int getId() {
        return id;
    }
}