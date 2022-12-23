package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Netflix {
    ArrayList<Material> materials;
    User credential;
    Boolean isLogin = false;

    public Netflix(ArrayList<Material> materials) {
        this.materials = materials;
    }
    public void login(User user){
        if (credential.getUsername().equals(user.getUsername()) && credential.getPassword().equals(user.getPassword()))
            this.isLogin = true;
        else
            System.out.println("Username or password is incorrect");
    }

    public void addMovie(Movie m1){
        if (isLogin)
            this.materials.add(m1);
        else
            System.out.println("You must login first");
    }

    public void addBook(Book b1){
        if (isLogin)
            this.materials.add(b1);
        else
            System.out.println("You must login first");
    }

    public void addMaterial(Material m2){
        if (isLogin)
            this.materials.add(m2);
        else
            System.out.println("You must login first");
    }

    public void findMaxScoreMaterial(){
        Double max = materials
                .stream()
                .mapToDouble(m -> m.getAvgScore())
                .max().orElse(0.0);

        Material maxMat = materials.stream().filter(m1 -> m1.getAvgScore() == max).findAny().orElse(null);;

        if (maxMat == null)
            System.out.println("Not found");
        else
            maxMat.showDetails();
    }

    public void findMinScoreMovie(){
        Double min = materials.stream().filter(m -> m.type == MaterialType.MOVIE)
                .mapToDouble(m -> m.getAvgScore()).min().orElse(0.0);

        Material minMovie = materials.stream().filter(m1 -> m1.getAvgScore() == min).findAny().orElse(null);;

        if (minMovie == null)
            System.out.println("Not found");
        else
            minMovie.showDetails();
    }

    public void findMostExpensiveMaterialByCategoryID(int category_id){
        int max =  materials.stream().filter(m -> m.category.id == category_id).collect(Collectors.toList())
                .stream().mapToInt( m1 -> m1.price).max().orElse(0);

        Material minMat = materials.stream().filter(m2 -> m2.price == max).findAny().orElse(null);

        if (minMat == null)
            System.out.println("Not found");
        else
            minMat.showDetails();
    }

    public void findMoviesByActorId(int actor_id){
        List<Movie> movies = materials.stream().filter(m -> m.type == MaterialType.MOVIE)
                .map(Movie.class::cast).collect(Collectors.toList());

        ArrayList<Movie> actorMovies = (ArrayList<Movie>) movies.stream()
                .filter(m -> m.actors.stream().anyMatch(a -> a.id == actor_id))
                .collect(Collectors.toList());

        System.out.println("Actor_id: " + actor_id + " movies");
        actorMovies.stream().forEach(m1 -> m1.showDetails());
    }
}
