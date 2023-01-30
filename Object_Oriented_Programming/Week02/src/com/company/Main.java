/*
Create a Worker class includes
    Attributes
        name (string
        socialSecurityNumber (int)
        wage (float)
        workingHours (int)
    Behaviours
        displayInfo()
            Print name + socialSecurityNumber;
        displaySalary()
            Print salary (salary= wage * workingHours)
Create a worker object and initialize attributes.
Call displayInfo() and displaySalary() methods for worker object.
Create another worker, and this time get attributes from the keyboard
 */
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Worker worker1 = new Worker();
        worker1.name = "Tom";
        worker1.socialSecurityNumber = 2020202002;
        worker1.wage = 20;
        worker1.workingHours = 60;

        Scanner scanner = new Scanner(System.in);

        System.out.printf("Your name:");
        String name = scanner.nextLine();

        System.out.printf("Your Social Security Number:");
        int socialSecurityNumber = scanner.nextInt();

        System.out.printf("Your Wage:");
        float wage = scanner.nextFloat();

        System.out.printf("Your Working Hours:");
        int workingHours = scanner.nextInt();

        Worker worker2 = new Worker();
        worker2.name = name;
        worker2.socialSecurityNumber = socialSecurityNumber;
        worker2.wage = wage;
        worker2.workingHours = workingHours;

        worker1.displayInfo();
        worker1.displaySalary();

        worker2.displayInfo();
        worker2.displaySalary();
    }
}
