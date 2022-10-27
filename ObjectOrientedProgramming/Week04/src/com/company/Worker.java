package com.company;

public class Worker {
    String name;
    int salary;
    static int counter;

    public Worker(String name, int salary) {
        this.name = name;
        setSalary(salary);
        counter++;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSalary(int salary) {
        if (salary <= 0)
            throw new SalaryException("Salary amount must be greater than zero");
        else
            this.salary = salary;
    }
}
/*
Create a Worker class which contains name salary attributes
Create setName and setSalary methods.
Your program should throw an exception when salary value is less than zero. (When you enter an illegal argument)
The exception message is “salary amount must be greater than zero”
In main method handle the exception and display the exception message.

Add another attribute (counter) which must be shared by all the instances of Worker class.
Create three workers and display number of total workers using counte variable.
 */
