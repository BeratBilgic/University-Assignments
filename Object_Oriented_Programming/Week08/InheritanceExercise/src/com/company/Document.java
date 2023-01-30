package com.company;

import java.util.ArrayList;

public class Document {
    private ArrayList<String> authors = new ArrayList<>();
    private DateInfo date;

    public Document(ArrayList<String> authors, DateInfo date) {
        this.authors = authors;
        this.date = date;
    }

    public void addAuthor(String name){
        this.authors.add(name);
    }

    public void displayInfo(){
        System.out.printf("DOCUMENT INFO --- ");
        for (String s: authors) {
            System.out.printf("%s - ", s);
        }
        System.out.printf("%s\n", date);
    }

    public ArrayList<String> getAuthors() {
        return authors;
    }

    public DateInfo getDate() {
        return date;
    }

}
