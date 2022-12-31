package com.company;

import java.util.ArrayList;

public class Movie extends Asset {
    ArrayList<Consumer> actors;
    Consumer director;

    public Movie(int id, String name, ArrayList<Integer> scores, int release_Year,
                 Category category, int price, String type, ArrayList<Consumer> actors, Consumer director) {
        super(id, name, scores, release_Year, category, price, type);
        this.actors = actors;
        this.director = director;
    }

    public void addActor(Consumer actor){
        this.actors.add(actor);
    }

    public boolean deleteActor(int consumerId){
        Consumer c = this.actors.stream().filter(a -> a.id == consumerId).findAny().orElse(null);
        if (c == null)
            return false;
        else{
            this.actors.remove(c);
            return true;
        }
    }


    @Override
    public void showDetail() {
        System.out.println("Movie{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", scores=" + scores +
                ", release_Year=" + release_Year +
                ", category=" + category +
                ", price=" + price +
                ", type='" + type + '\'' +
                ", actors=" + actors +
                "\n, director=" + director +
                '}');
    }
}
