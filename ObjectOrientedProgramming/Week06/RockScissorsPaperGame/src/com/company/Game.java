package com.company;

public class Game {
    private Gamer g1, g2;
    private static boolean isGameOver;

    public Game(Gamer g1, Gamer g2) {
        this.g1 = g1;
        this.g2 = g2;
    }

    public void startGame(){
        do {
            g1.move();
            g2.move();
            StatMaker.processMoves(g1, g2);
            StatMaker.displayScores(g1, g2);
        }while (isGameOver == false);
    }

    public Gamer getG1() {
        return g1;
    }

    public void setG1(Gamer g1) {
        this.g1 = g1;
    }

    public Gamer getG2() {
        return g2;
    }

    public void setG2(Gamer g2) {
        this.g2 = g2;
    }

    public static boolean isIsGameOver() {
        return isGameOver;
    }

    public static void setIsGameOver(boolean isGameOver) {
        Game.isGameOver = isGameOver;
    }
}
