package com.company;

import javax.net.ssl.SNIHostName;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;

public class Gamer {
    String name;
    int numberofWins;
    static int numberofDraws;
    static int numberOfTrials;
    HandSign handSign;

    Gamer(String name){
        this.name =name;
    }

    void move(){
        if (Game.isGameOver) return;
        boolean isInputInvalid=false;
        Scanner userInput = new Scanner(System.in);
       System.out.println("please enter q for quit, " +
                "r for rock, s for scissor, p for paper");
        do{
            isInputInvalid=false;
            System.out.println(this.name +" ! your turn!");
            String choice = userInput.next().toLowerCase();

            switch (choice)
            {
                case "q":
                    Game.isGameOver=true;
                    break;
                case "r":
                   this.handSign = HandSign.ROCK;
                    break;
                case "s":
                    this.handSign = HandSign.SCISSOR;
                    break;
                case "p":
                    this.handSign = HandSign.PAPER;
                    break;
                default:
                    isInputInvalid=true;
                    break;
            }
        }while(isInputInvalid);
    }

    void moveAutomatic(){
        Random random = new Random();
        int decision = random.nextInt(3); //it can take 0 or 1 or 2;
        switch (decision){
            case 0:
                this.handSign = HandSign.ROCK;
                break;
            case 1:
                this.handSign = HandSign.SCISSOR;
                break;
            case 2:
                this.handSign = HandSign.PAPER;
                break;
        }

        //System.out.println(this.name+"'s choice is: "+this.handSign);
    }
}
