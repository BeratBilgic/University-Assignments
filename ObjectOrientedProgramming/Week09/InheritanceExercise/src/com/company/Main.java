package com.company;

public class Main {

    public static void main(String[] args) {
        Document doc = new Document(new String[]{"Document Author1", "Document Author2"},
                new DateInfo(2022, 12, 28));
        Book b1 = new Book(new String[]{"Book Author1", "Book Author2"},
                new DateInfo(2021, 11, 27), "Book Title");
        EMail em1 = new EMail(new String[]{"Email Author1", "Email Author2"},
                new DateInfo(2020, 10, 26), "E-mail Subject",
                new String[]{"to name1", "to name2"});

        printStringArray(doc.getAuthors());
        System.out.println(doc.getDate().toString());

        printStringArray(b1.getAuthors());
        System.out.println(b1.getDate().toString() + " " + b1.getTitle());

        printStringArray(em1.getAuthors());
        System.out.print(em1.getDate().toString() + " " + em1.getSubject() + " ");
        printStringArray(em1.getTo());

        System.out.println("\n");
        b1.addAuthor("New Book Author");
        printStringArray(b1.getAuthors());

    }

    public static void printStringArray(String[] strings){
        for (String s: strings){
            System.out.printf("-%s ",s);
        }
    }
}
