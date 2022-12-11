package com.company;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        Document doc1 = new Document(new ArrayList<>(Arrays.asList("Document Author1", "Document Author2")),
                new DateInfo(2022, 12, 28));

        Book b1 = new Book(new ArrayList<>(Arrays.asList("Book Author1", "Book Author2")),
                new DateInfo(2021, 11, 27), "Book Title");

        EMail em1 = new EMail(new ArrayList<>(Arrays.asList("E-mail Author1", "E-mail Author2")),
                new DateInfo(2020, 10, 26), "E-mail Subject",
                new ArrayList<>(Arrays.asList("to name1", "to name2")));

        doc1.displayInfo();
        b1.displayInfo();
        em1.displayInfo();

        doc1.addAuthor("New Document Author3");
        doc1.displayInfo();
    }
}
