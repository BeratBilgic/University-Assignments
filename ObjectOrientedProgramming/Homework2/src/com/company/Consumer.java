package com.company;

public class Consumer {
    int id;
    int birthYear;
    int salary;
    String firstName;
    String lastName;

    public Consumer(int id, int birthYear, int salary, String firstName, String lastName) {
        this.id = id;
        this.birthYear = birthYear;
        this.salary = salary;
        this.firstName = firstName;
        this.lastName = lastName;
    }

    @Override
    public String toString() {
        return "\nConsumer{" +
                "id=" + id +
                ", birthYear=" + birthYear +
                ", salary=" + salary +
                ", firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                '}';
    }

    public int getBirthYear() {
        return birthYear;
    }

    public int getSalary() {
        return salary;
    }
}
