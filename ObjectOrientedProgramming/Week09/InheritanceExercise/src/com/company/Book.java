package com.company;

public class Book extends Document{
    private String title;

    public Book(String[] authors, DateInfo date, String title) {
        super(authors, date);
        this.title = title;
    }

    public String getTitle() {
        return title;
    }
}
