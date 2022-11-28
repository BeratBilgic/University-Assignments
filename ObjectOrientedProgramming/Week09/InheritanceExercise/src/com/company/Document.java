package com.company;

public class Document {
    private String[] authors;
    private DateInfo date;

    public Document(String[] authors, DateInfo date) {
        this.authors = authors;
        this.date = date;
    }

    public void addAuthor(String name){
        String[] arr = new String[this.authors.length + 1];
        int i;

        for ( i = 0; i < this.authors.length; i++) {
            arr[i] = this.authors[i];
        }
        arr[i] = name;

        this.authors = arr;
    }

    public String[] getAuthors() {
        return authors;
    }

    public DateInfo getDate() {
        return date;
    }
}
