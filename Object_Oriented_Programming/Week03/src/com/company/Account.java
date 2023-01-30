package com.company;

import java.util.Scanner;

public class Account {
    private double balance;
    private String ownerName;

    public Account(Double balance, String ownerName) {
        this.balance = balance;
        this.ownerName = ownerName;
    }

    public void add(double amount){
        this.balance += amount;
    }

    public void withdraw(double amount){
        String password = "1234", userPass;
        Boolean isMatched = false;
        Scanner scanner = new Scanner(System.in);

        for (int i = 3; i > 0 ; i--) {
            System.out.println("Please enter the 4-digit userPass: ");
            userPass = scanner.nextLine();
            if (userPass.equals(password)) {
                this.balance -= amount;
                isMatched = true;
                break;
            }else if(i != 1){
                System.out.printf("Your password is wrong, you can try again %d more times.\n", i-1);
            }
        }
        if (!isMatched){
            System.out.println("Your account has been blocked, please try again later.");
        }
    }

    public Double getBalance() {
        return balance;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }
}

/*
You need to do the following modification in Account Class:
In order to withdraw money, there will be a set of conditions:
Set a password (for example 1234)
User will get a message: “Please enter the 4-digit pass:”
User must enter the pass using keyboard
If pass is true, the user will withdraw the money
If pass is wrong, the user will try again two more times.
If the pass is still wrong, the user will get another message:
“Your account has been blocked, please try again later”

Do them all in withdraw() Method
 */