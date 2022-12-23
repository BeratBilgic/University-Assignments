package com.company;

import java.util.ArrayList;

public class Book extends Material{
    private Person writer;
    int numberOfPages;

    public Book(int id, String name, ArrayList<Integer> scores,
                int release_Year, Category category, int price, MaterialType type, Person writer, int numberOfPages) {
        super(id, name, scores, release_Year, category, price, type);
        this.writer = writer;
        this.numberOfPages = numberOfPages;
    }

    @Override
    public void showDetails() {
        System.out.println("\n--Book Detail--\nid: " + this.id + "\nName: " + name + "\nRelease Year: " + release_Year
        + "\nCategory: " + category + "\nPrice: " + price + "\nMaterialType: "+ type + "\nWriter: " + writer
                + "\nNumber Of Pages: " + numberOfPages);
        System.out.println("Scores: ");
        showArrayListContent(scores);
    }

    public void setWriter(Person writer) {
        this.writer = writer;
    }
}
