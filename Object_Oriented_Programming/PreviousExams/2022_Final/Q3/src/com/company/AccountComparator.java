package com.company;

import java.util.Comparator;

public class AccountComparator implements Comparator<BankAccount> {

    @Override
    public int compare(BankAccount o1, BankAccount o2) {
        return o1.compareTo(o2);
    }
}
