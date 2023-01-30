package com.company;

public class User extends Consumer {
    boolean loginStatus = false;
    String username;
    String password;

    public User(int id, String firstName, String lastName, String username, String password) {
        super(id, 0, 0, firstName, lastName);
        this.username = username;
        this.password = password;
    }
}
