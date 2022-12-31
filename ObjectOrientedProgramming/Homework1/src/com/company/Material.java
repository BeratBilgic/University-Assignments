package com.company;

import java.util.ArrayList;

public abstract class Material {
    int id;
    String name;
    ArrayList<Integer> scores;
    int release_Year;
    Category category;
    int price;
    MaterialType type;

    public Material(int id, String name, ArrayList<Integer> scores,
                    int release_Year, Category category, int price, MaterialType type) {
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

    public double getAvgScore(){
        Double average = scores.stream().mapToInt(val -> val).average().orElse(0.0);
        return average;
    }

    public void showDetails() {};

    protected void showArrayListContent(ArrayList arrayList){
        arrayList.stream().forEach(i-> System.out.println(i));
    }
}
