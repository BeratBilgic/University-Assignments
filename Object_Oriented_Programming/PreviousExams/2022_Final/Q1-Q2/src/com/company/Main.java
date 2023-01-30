package com.company;

public class Main {

    public static void main(String[] args) {
        Student student1 = new BachelorStudent(10,50,90);
        Student student2 = new MasterStudent(10,50,90,5);
        Student student3 = new PhDStudent(10,50,90,2,1);

        //student1.projectScore(); //cannot be compiled
        ((ConferenceScoreBehaviour)student3).conferenceScore();
        //((ArticleScoreBehaviour)student2).articleScore(); //compiles but doesn't run
        //student2.articleScore();  //cannot be compiled
        //((ProjectScoreBehaviour)student3).projectScore(); //compiles but doesn't run

    }
}
