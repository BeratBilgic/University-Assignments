package com.company;

public enum Branch {
    MATH("information regarding math"),
    PHYSICS("information regarding physics"),
    CS("information regarding cs"),
    ENG("information regarding eng");

    private final String description;

    Branch(String description) {
        this.description = description;
    }

    public String getDescription() {
        return description;
    }
}
