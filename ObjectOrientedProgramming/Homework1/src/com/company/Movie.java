package com.company;

import java.util.ArrayList;

public class Movie extends Material{
    ArrayList<Person> actors;
    Person director;

    public Movie(int id, String name, ArrayList<Integer> scores, int release_Year,
                 Category category, int price, MaterialType type, ArrayList<Person> actors, Person director) {
        super(id, name, scores, release_Year, category, price, type);
        this.actors = actors;
        this.director = director;
    }

    void addActor(Person actor){
        this.actors.add(actor);
    }

    @Override
    public void showDetails() {
        System.out.println("\n--Movie Detail--\nid: " + this.id + "\nName: " + name + "\nRelease Year: " + release_Year
                + "\nCategory: " + category + "\nPrice: " + price + "\nMaterialType: "+ type
                + "\nDirector: " + director + "\nActors: ");
        showArrayListContent(actors);
        System.out.println("Scores: ");
        showArrayListContent(scores);
    }
}
