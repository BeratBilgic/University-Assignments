package com.company;

public class Main {

    public static void main(String[] args) {
	    Person p1 = new Person(10,"name1","surname2",20);
        Person p2 = new Person("name2","surname2");
        Person p3 = new Person(20);
        Person p4 = new Person();

        Person[] people = {p1, p2, p3, p4};

        System.out.printf("%-5s%-22s%-22s%-5s\n", "Id", "First Name", "Last Name", "Age");
        for (Person p : people) {
            System.out.printf("%-5d%-22s%-22s%-5d\n", p.getId(), p.getFirstName(), p.getLastName(), p.getAge());
        }
    }
}
