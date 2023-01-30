package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	    Consumer actor1 = new Consumer(1,1991,1100,"name1","lastname1");
        Consumer actor2 = new Consumer(2,1992,1200,"name2","lastname2");
        Consumer actor3 = new Consumer(3,1993,1300,"name3","lastname3");
        Consumer actor4 = new Consumer(4,1994,1400,"name4","lastname4");
        Consumer actor5 = new Consumer(5,1995,1500,"name5","lastname5");
        Consumer actor6 = new Consumer(6,1996,1600,"name6","lastname6");

        Consumer director1 = new Consumer(11,1981,2100,"director1","director1");
        Consumer director2 = new Consumer(12,1982,2200,"director2","director2");
        Consumer director3 = new Consumer(13,1983,2300,"director3","director3");

        Consumer writer1 = new Consumer(14,1971,3100,"writer1","writer1");
        Consumer writer2 = new Consumer(15,1972,3200,"writer2","writer2");
        Consumer writer3 = new Consumer(16,1973,3300,"writer3","writer3");

        Category c1 = new Category(1, "CATCODE1","catName1");
        Category c2 = new Category(2, "CATCODE2","catName2");
        Category c3 = new Category(3, "CATCODE3","catName3");
        Category c4 = new Category(4, "CATCODE4","catName4");

        ArrayList<Integer> scores1 = new ArrayList<>();
        ArrayList<Integer> scores2 = new ArrayList<>();
        ArrayList<Integer> scores3 = new ArrayList<>();
        ArrayList<Integer> scores4 = new ArrayList<>();
        ArrayList<Integer> scores5 = new ArrayList<>();
        ArrayList<Integer> scores6 = new ArrayList<>();

        ArrayList<Consumer> actors1 = new ArrayList<>();
        ArrayList<Consumer> actors2 = new ArrayList<>();
        ArrayList<Consumer> actors3 = new ArrayList<>();

        Movie mov1 = new Movie(1,"movname1",scores1, 1991, c1,10100, "movie", actors1, director1);
        mov1.addScore(60);
        mov1.addScore(50);
        mov1.addScore(100);
        mov1.addActor(actor1);
        mov1.addActor(actor4);
        mov1.addActor(actor6);
        Movie mov2 = new Movie(2,"movname2",scores2, 1992, c2,10200, "movie", actors2, director2);
        mov2.addScore(35);
        mov2.addScore(45);
        mov2.addScore(55);
        mov2.addActor(actor2);
        mov2.addActor(actor3);
        mov2.addActor(actor5);
        Movie mov3 = new Movie(3,"movname3",scores3, 1993, c2,10300, "movie", actors3, director3);
        mov3.addScore(75);
        mov3.addScore(55);
        mov3.addScore(65);
        mov3.addActor(actor4);
        mov3.addActor(actor5);
        mov3.addActor(actor6);

        Book book1 = new Book(1,"bookname1",scores4,1981,c3,5100, "book",writer1,100);
        book1.addScore(15);
        book1.addScore(25);
        book1.addScore(35);
        Book book2 = new Book(2,"bookname2",scores5,1982,c4,5200, "book",writer2,200);
        book2.addScore(55);
        book2.addScore(65);
        book2.addScore(75);
        Book book3 = new Book(3,"bookname3",scores6,1983,c4,5300, "book",writer3,300);
        book3.addScore(80);
        book3.addScore(100);
        book3.addScore(100);

        //4-Find the max, min scores for these movies.
        System.out.println("Movie1's max score: " + mov1.getMaxScore() + " min score: " + mov1.getMinScore());
        System.out.println("Movie2's max score: " + mov2.getMaxScore() + " min score: " + mov2.getMinScore());
        System.out.println("Movie3's max score: " + mov3.getMaxScore() + " min score: " + mov3.getMinScore());


        // 6-Print out the avarage score of specific book by using getAvarageScore method.
        System.out.println("Book1's avarage score :" + book1.getAvgScore());
        System.out.println("Book2's avarage score :" + book2.getAvgScore());
        System.out.println("Book3's avarage score :" + book3.getAvgScore());

        User user1 = new User(10,"name10","surname10" ,"username","1234");

        ArrayList<Asset> assets = new ArrayList<>();

        DisneyPlus disneyPlus = new DisneyPlus(assets);
        disneyPlus.credential = user1;

        User user2 = new User(10,"name10","surname10" ,"username","1234");

        disneyPlus.login(user2);

        disneyPlus.addMovie(mov1);
        disneyPlus.addMovie(mov2);
        disneyPlus.addMovie(mov3);
        disneyPlus.addBook(book1);
        disneyPlus.addBook(book2);
        disneyPlus.addBook(book3);

        System.out.println("\n******** N1 - findOldestActor *******");
        disneyPlus.findOldestActor();
        System.out.println("\n******** N2 - findMinScoreMovie *******");
        disneyPlus.findMinScoreMovie();
        System.out.println("\n******** N3 - findHighestPaidActor *******");
        disneyPlus.findHighestPaidActor(2);
        System.out.println("\n******** N4 - findMostCheapestAssetByCategoryID *******");
        disneyPlus.findMostCheapestAssetByCategoryID(4);
        System.out.println("\n******** N5 - findMoviesByActorId *******");
        disneyPlus.findMoviesByActorId(4);
        System.out.println("\n******** N6 - findHighestAvgScoreAsset *******");
        disneyPlus.findHighestAvgScoreAsset();
    }
}
