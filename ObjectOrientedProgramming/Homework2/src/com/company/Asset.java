package com.company;

import java.util.ArrayList;

public abstract class Asset {
    int id;
    String name;
    ArrayList<Integer> scores;
    int release_Year;
    Category category;
    int price;
    String type; //"movie" or "book"

    public Asset(int id, String name, ArrayList<Integer> scores,
                 int release_Year, Category category, int price, String type) {
        this.id = id;
        this.name = name;
        this.scores = scores;
        this.release_Year = release_Year;
        this.category = category;
        this.price = price;
        this.type = type;
    }

    public void addScore(int score){
        this.scores.add(score);
    }

    public int getMaxScore(){
        return this.scores.stream()
                .mapToInt(v -> v)
                .max().orElse(-1);
    }

    public int getMinScore(){
        return this.scores.stream()
                .mapToInt(v -> v)
                .min().orElse(-1);
    }

    public double getAvgScore(){
        Double average = scores.stream().mapToInt(val -> val).average().orElse(0.0);
        return average;
    }

    public void showDetail() {};

    public int getPrice() {
        return price;
    }
}
