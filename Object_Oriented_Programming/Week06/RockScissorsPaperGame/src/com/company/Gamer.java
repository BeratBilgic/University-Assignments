package com.company;

import java.util.Scanner;

public class Gamer {
    private static int numofDraw;
    private static int numofTrials;
    private int numofWin;
    private String name;
    private HandSign sign;

    public Gamer(String name) {
        this.name = name;
    }

    public void move(){
        if (Game.isIsGameOver())
            return;

        boolean isInputInvalid = false;
        Scanner scanner = new Scanner(System.in);
        System.out.println(this.name + " please enter p: paper s: scissor r: rock q: quit");

        do{
            String c = scanner.next().toLowerCase();
            isInputInvalid = false;
            switch (c)
            {
                case "q":
                    Game.setIsGameOver(true);
                    break;
                case "p":
                    sign = HandSign.PAPER;
                    break;
                case "s":
                    sign = HandSign.SCISSOR;
                    break;
                case "r":
                    sign = HandSign.ROCK;
                    break;
                default:
                    System.out.println("Your input is invalid, Please try again");
                    isInputInvalid = true;
                    break;
            }
        }while (isInputInvalid);
    }

    public static int getNumofDraw() {
        return numofDraw;
    }

    public static void setNumofDraw(int numofDraw) {
        Gamer.numofDraw = numofDraw;
    }

    public static int getNumofTrials() {
        return numofTrials;
    }

    public static void setNumofTrials(int numofTrials) {
        Gamer.numofTrials = numofTrials;
    }

    public int getNumofWin() {
        return numofWin;
    }

    public void setNumofWin(int numofWin) {
        this.numofWin = numofWin;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public HandSign getSign() {
        return sign;
    }

    public void setSign(HandSign sign) {
        this.sign = sign;
    }
}
