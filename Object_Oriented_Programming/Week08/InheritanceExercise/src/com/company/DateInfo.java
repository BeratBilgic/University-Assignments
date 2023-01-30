package com.company;

public class DateInfo {
    private int year;
    private int month;
    private int day;

    public DateInfo(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    @Override
    public String toString() {
        return day + "/" + month + "/" + year;
    }
}
