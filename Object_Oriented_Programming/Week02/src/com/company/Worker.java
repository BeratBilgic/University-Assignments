package com.company;

public class Worker {
    String name;
    int socialSecurityNumber;
    float wage;
    int workingHours;

    public void displayInfo(){
        System.out.println("Name : " + name + "\nSocial Security Number: " + socialSecurityNumber);
    }

    public void displaySalary(){
        int salary= (int) (wage * workingHours);
        System.out.println("Salary :" + salary);
    }
}
