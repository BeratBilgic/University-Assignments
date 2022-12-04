package com.company;

import java.util.ArrayList;

public class Book extends Document{
    private String title;

    public Book(ArrayList<String> authors, DateInfo date, String title) {
        super(authors, date);
        this.title = title;
    }

    @Override
    public void displayInfo() {
        System.out.printf("BOOK INFO --- ");
        for (String s: getAuthors()) {
            System.out.printf("%s - ", s);
        }
        System.out.printf("%s ", getDate());
        System.out.printf("***%s***\n", title);
    }

    public String getTitle() {
        return title;
    }
}
