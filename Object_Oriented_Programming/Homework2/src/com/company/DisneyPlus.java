package com.company;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class DisneyPlus {
    ArrayList<Asset> assets;
    User credential = null;
    Boolean isLogin = false;

    public DisneyPlus(ArrayList<Asset> assets) {
        this.assets = assets;
    }

    public void login(User user){
        if (credential.username.equals(user.username) && credential.password.equals(user.password)){
            this.isLogin = true;
            credential.loginStatus = true;
        }
        else
            System.out.println("Username or password is incorrect");
    }

    public void addMovie(Movie m1){
        if (credential.loginStatus && isLogin)
            this.assets.add(m1);
        else
            System.out.println("You must login first");
    }

    public boolean removeMovie(int movieId){
        if (!credential.loginStatus && !isLogin)
            System.out.println("You must login first");

        Movie m = (Movie) this.assets
                .stream()
                .filter(a -> a.id == movieId && a.type.equals("movie"))
                .findAny()
                .orElse(null);

        if (m == null)
            return false;

        this.assets.remove(m);
        return true;
    }


    public void addBook(Book b1){
        if (credential.loginStatus && isLogin)
            this.assets.add(b1);
        else
            System.out.println("You must login first");
    }

    public boolean removeBook(int bookId){
        if (!credential.loginStatus && !isLogin)
            System.out.println("You must login first");

        Book b = (Book) this.assets
                .stream()
                .filter(a -> a.id == bookId && a.type.equals("book"))
                .findAny()
                .orElse(null);

        if (b == null)
            return false;

        this.assets.remove(b);
        return true;
    }

    public void addAsset(Asset m2){
        if (credential.loginStatus && isLogin)
            this.assets.add(m2);
        else
            System.out.println("You must login first");
    }

    //N1- Create the function that displays the information of the OLDEST actors.
    public void findOldestActor(){
        ArrayList<Movie> movies = (ArrayList<Movie>) findAllMovies();

        List<Consumer> actors = movies.stream()
                .flatMap(m -> m.actors.stream()
                        .distinct())
                .collect(Collectors.toList());

        Consumer oldestActor = actors.stream()
                .min(Comparator.comparing(Consumer::getBirthYear))
                .orElse(null);

        if (oldestActor == null)
            System.out.println("Not found");
        else
            System.out.println(oldestActor);
    }

    //N2-Create the function that displays the information of the movie with the lowest average score on the screen.
    public void findMinScoreMovie(){
        Movie minMovie = (Movie) assets.stream()
                .filter(m -> m.type.equals("movie"))
                .min(Comparator.comparing(Asset::getAvgScore))
                .orElse(null);

        if (minMovie == null)
            System.out.println("Not found");
        else
            minMovie.showDetail();
    }

    //N3-Create a function that takes a "movie_id" as a parameter and displays information of highest paid actor in that movie.
    public void findHighestPaidActor(int movie_id){
        Movie movie = (Movie) assets
                .stream()
                .filter(a -> a.id == movie_id && a.type.equals("movie"))
                .findFirst()
                .orElse(null);

        Consumer actor = movie == null ? null : movie.actors.stream()
                .max(Comparator.comparing(Consumer::getSalary))
                .orElse(null);

        if (actor == null)
            System.out.println("Not found");
        else{
            System.out.print("Highest paid actor in id:" + movie_id +" movie");
            System.out.println(actor);
        }
    }

    //N4-Create a function that takes a "category id" as a parameter and displays information on the most cheapest Asset in that category of DisneyPlus.
    public void findMostCheapestAssetByCategoryID(int category_id){
        Asset minAsset = assets.stream().filter(a -> a.category.id == category_id).collect(Collectors.toList())
                .stream()
                .min(Comparator.comparing(Asset::getPrice))
                .orElse(null);

        if (minAsset == null)
            System.out.println("Not found");
        else{
            System.out.println("Category id: " + category_id);
            minAsset.showDetail();
        }
    }

    //N5-Create a function that takes a Consumer's id as a parameter and displays the information of all movies acted by him/her on the screen.
    public void findMoviesByActorId(int actor_id){
        ArrayList<Movie> movies = (ArrayList<Movie>) findAllMovies();

        ArrayList<Movie> actorMovies = (ArrayList<Movie>) movies.stream()
                .filter(m -> m.actors.stream().anyMatch(a -> a.id == actor_id))
                .collect(Collectors.toList());

        System.out.println("Actor_id: " + actor_id + " movies");
        actorMovies.stream().forEach(m1 -> m1.showDetail());
    }

    //N6- Create the function that displays the information of the object with the highest average score among all Assets..
    public void findHighestAvgScoreAsset(){
        Asset maxMat = assets
                .stream()
                .max(Comparator.comparing(Asset::getAvgScore))
                .orElse(null);

        if (maxMat == null)
            System.out.println("Not found");
        else
            maxMat.showDetail();
    }

    protected List<Movie> findAllMovies(){
        return assets.stream().filter(m -> m.type.equals("movie"))
                .map(Movie.class::cast).collect(Collectors.toList());
    }
}
