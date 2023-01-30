package com.company;

import java.util.Scanner;

import static com.company.ExceptionHandlingLabExercise.runExceptionHandlingLabExercise;

public class Main {

    public static void main(String[] args) {
        //Lab Exercise 1: Exception Handling
        runExceptionHandlingLabExercise();

        //Lab Exercise 2: Creating your own Exception
        Worker worker1 = new Worker("name1",100);
        System.out.println("Worker counter :" + worker1.counter);
        Worker worker2 = new Worker("name2",100);
        System.out.println("Worker counter :" + worker2.counter);
        Worker worker3 = new Worker("name3",100);
        System.out.println("Worker counter :" + worker3.counter);

        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter your salary: ");
            int salary = scanner.nextInt();
            worker1.setSalary(salary);
        }catch (SalaryException e){
            System.out.println(e.getMessage());
        }
        System.out.println("Worker counter :" + worker1.counter);
    }
}

