package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	    Person p1 = new Person(1,"pname1","plastname1",21);
        Person p2 = new Person(2,"pname2","plastname2",22);
        Person p3 = new Person(3,"pname3","plastname3",23);
        Person p4 = new Person(4,"pname4","plastname4",24);
        Person p5 = new Person(5,"pname5","plastname5",25);
        Person p6 = new Person(6,"pname6","plastname6",26);

        Person p11 = new Person(11,"director1","director1",31);
        Person p12 = new Person(12,"director2","director2",32);
        Person p13 = new Person(13,"director3","director3",33);

        Person p14 = new Person(14,"writer1","writer1",41);
        Person p15 = new Person(15,"writer2","writer2",42);
        Person p16 = new Person(16,"writer3","writer3",43);

        Category c1 = new Category(1, "catCode1","carName1");
        Category c2 = new Category(2, "catCode2","carName2");
        Category c3 = new Category(3, "catCode3","carName3");
        Category c4 = new Category(4, "catCode4","carName4");
        Category c5 = new Category(5, "catCode5","carName5");
        Category c6 = new Category(6, "catCode6","carName6");

        ArrayList<Integer> sco1 = new ArrayList<>();
        sco1.add(50);
        sco1.add(100);
        ArrayList<Person> ac1 = new ArrayList<>();
        ac1.add(p1);
        ac1.add(p4);
        ac1.add(p6);

        ArrayList<Integer> sco2 = new ArrayList<>();
        sco2.add(35);
        sco2.add(45);
        sco2.add(55);
        ArrayList<Person> ac2 = new ArrayList<>();
        ac2.add(p2);
        ac2.add(p3);

        ArrayList<Integer> sco3 = new ArrayList<>();
        sco3.add(55);
        sco3.add(65);
        sco3.add(75);
        ArrayList<Person> ac3 = new ArrayList<>();
        ac3.add(p4);
        ac3.add(p5);
        ac3.add(p6);

        Movie mov1 = new Movie(1,"movname1",sco1, 1991, c1,101,MaterialType.MOVIE, ac1, p11);
        Movie mov2 = new Movie(2,"movname2",sco2, 1992, c2,102,MaterialType.MOVIE, ac2, p12);
        Movie mov3 = new Movie(3,"movname3",sco3, 1993, c2,103,MaterialType.MOVIE, ac3, p13);

        ArrayList<Integer> sco4 = new ArrayList<>();
        sco4.add(15);
        sco4.add(25);
        sco4.add(35);

        ArrayList<Integer> sco5 = new ArrayList<>();
        sco5.add(50);
        sco5.add(60);
        sco5.add(65);

        ArrayList<Integer> sco6 = new ArrayList<>();
        sco6.add(80);
        sco6.add(90);
        sco6.add(100);

        Book book1 = new Book(1,"bookname1",sco4,1981,c3,51,MaterialType.BOOK,p14,100);
        Book book2 = new Book(2,"bookname2",sco5,1982,c4,52,MaterialType.BOOK,p15,200);
        Book book3 = new Book(3,"bookname3",sco6,1983,c4,53,MaterialType.BOOK,p16,300);

        ArrayList<Material> materials = new ArrayList<>();
        materials.add(mov1);
        materials.add(mov2);
        materials.add(book1);
        materials.add(book2);

        User user1 = new User(1,"name1","surname1" ,"username","1234");

        Netflix netflix = new Netflix(materials);
        netflix.credential = user1;

        User user2 = new User(1,"name1","surname1" ,"username","1234");

        netflix.login(user2);

        netflix.addMovie(mov3);
        netflix.addBook(book3);

        System.out.println("\n******** N1 - findMaxScoreMaterial *******");
        netflix.findMaxScoreMaterial();
        System.out.println("\n******** N2 - findMinScoreMovie *******");
        netflix.findMinScoreMovie();
        System.out.println("\n******** N3 - findMostExpensiveMaterialByCategoryID *******");
        netflix.findMostExpensiveMaterialByCategoryID(2);
        System.out.println("\n******** N4 - findMoviesByActorId *******");
        netflix.findMoviesByActorId(4);

    }
}
