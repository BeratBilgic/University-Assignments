package com.company;

public class User extends Person{
    private String username;
    private String password;

    public User(int id, String firstName, String lastName, String username, String password) {
        super(id, firstName, lastName);
        this.username = username;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
