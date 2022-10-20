package com.company;

public class Main {

    public static void main(String[] args) {
	    Account acc1 = new Account(2000.0, "Tom");
        System.out.println("Name :" + acc1.getOwnerName());
        System.out.println("Balance :" + acc1.getBalance());
        acc1.add(500);
        System.out.println("Name :" + acc1.getOwnerName());
        System.out.println("Balance :" + acc1.getBalance());
        acc1.withdraw(1000);
        System.out.println("Name :" + acc1.getOwnerName());
        System.out.println("Balance :" + acc1.getBalance());
    }
}
