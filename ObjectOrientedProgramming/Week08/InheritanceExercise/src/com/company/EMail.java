package com.company;

import java.util.ArrayList;

public class EMail extends Document{
    private String subject;
    private ArrayList<String> to = new ArrayList<>();

    public EMail(ArrayList<String> authors, DateInfo date, String subject, ArrayList<String> to) {
        super(authors, date);
        this.subject = subject;
        this.to = to;
    }

    @Override
    public void displayInfo() {
        System.out.printf("E-MAİL INFO --- ");
        for (String s: getAuthors()) {
            System.out.printf("%s - ", s);
        }
        System.out.printf("%s ", getDate());
        System.out.printf("***%s*** ", subject);
        for (String s: to) {
            System.out.printf("%s - ", s);
        }
        System.out.println();
    }

    public String getSubject() {
        return subject;
    }

    public ArrayList<String> getTo() {
        return to;
    }
}
