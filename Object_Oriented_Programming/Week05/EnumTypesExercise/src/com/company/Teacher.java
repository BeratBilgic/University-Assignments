package com.company;

public class Teacher {
    private int id;
    private Branch branch;

    public Teacher(int id, Branch branch) {
        this.id = id;
        this.branch = branch;
    }

    public Branch getBranch() {
        return branch;
    }
}
