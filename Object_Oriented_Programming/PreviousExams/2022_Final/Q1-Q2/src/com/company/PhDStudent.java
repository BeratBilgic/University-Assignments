package com.company;

public class PhDStudent extends MasterStudent implements ArticleScoreBehaviour{
    int numberOfArticles;

    public PhDStudent(int id, float mid, float fin, int numberOfConf, int numberOfArticles) {
        super(id, mid, fin, numberOfConf);
        this.numberOfArticles = numberOfArticles;
    }

    @Override
    float computeTotalScore() {
        return super.computeTotalScore() + articleScore();
    }

    @Override
    public float articleScore() {
        return numberOfArticles * 8;
    }
}
