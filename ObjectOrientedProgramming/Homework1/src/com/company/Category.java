package com.company;

public class Category {
    int id;
    String categoryCode;
    String categoryName;

    public Category(int id, String categoryCode, String categoryName) {
        this.id = id;
        this.categoryCode = categoryCode;
        this.categoryName = categoryName;
    }

    @Override
    public String toString() {
        return "Category{" +
                "id=" + id +
                ", categoryCode='" + categoryCode + '\'' +
                ", categoryName='" + categoryName + '\'' +
                '}';
    }
}
