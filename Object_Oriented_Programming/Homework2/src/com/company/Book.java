package com.company;

import java.util.ArrayList;

public class Book extends Asset {
    private Consumer writer;
    int numberOfPages;

    public Book(int id, String name, ArrayList<Integer> scores, int release_Year,
                Category category, int price, String type, Consumer writer, int numberOfPages) {
        super(id, name, scores, release_Year, category, price, type);
        this.writer = writer;
        this.numberOfPages = numberOfPages;
    }

    @Override
    public void showDetail() {
        System.out.println("Book{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", scores=" + scores +
                ", release_Year=" + release_Year +
                ", category=" + category +
                ", price=" + price +
                ", type='" + type + '\'' +
                ", writer=" + writer +
                "\n, numberOfPages=" + numberOfPages +
                '}');
    }

    public void setWriter(Consumer newWriter) {
        this.writer = newWriter;
    }
}
