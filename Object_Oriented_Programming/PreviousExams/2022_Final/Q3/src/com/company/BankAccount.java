package com.company;

public class BankAccount implements Comparable<BankAccount>{
    private int accountNo;
    private String holderName;
    private Double balance;

    public BankAccount(int accountNo, String holderName, Double balance) {
        this.accountNo = accountNo;
        this.holderName = holderName;
        this.balance = balance;
    }

    void balanceChange(double amount){
        this.balance-=amount;
    }

    @Override
    public int compareTo(BankAccount o) {
        return holderName.compareTo(o.holderName);
    }

    @Override
    public String toString() {
        return "BankAccount{" +
                "accountNo=" + accountNo +
                ", holderName='" + holderName + '\'' +
                ", balance=" + balance +
                '}';
    }
}
