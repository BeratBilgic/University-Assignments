package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class Main {

    public static void main(String[] args) {
        ArrayList<BankAccount> myAccounts = new ArrayList<>();
        BankAccount a1 = new BankAccount(1,"bbbb",5000.0);
        BankAccount a2 = new BankAccount(2,"dddd",4000.0);
        BankAccount a3 = new BankAccount(3,"cccc",3000.0);
        BankAccount a4 = new BankAccount(4,"aaaa",2000.0);

        myAccounts.add(a1);
        myAccounts.add(a2);
        myAccounts.add(a3);
        myAccounts.add(a4);

        //with Comparable interface
        Collections.sort(myAccounts);

        //with Comparator interface
        Collections.sort(myAccounts, new AccountComparator());

        Iterator<BankAccount> iterator= myAccounts.iterator();
        while (iterator.hasNext()){
            BankAccount bankAccount = iterator.next();
            bankAccount.balanceChange(500);
            System.out.println(bankAccount);
        }
    }
}
