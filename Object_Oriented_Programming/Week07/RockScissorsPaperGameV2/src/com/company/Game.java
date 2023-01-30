package com.company;

public class Game {
    private Gamer g1, g2;
    private static boolean isGameOver;

    public Game(Gamer g1, Gamer g2) {
        this.g1 = g1;
        this.g2 = g2;
    }

    public void startGamePvP(){
        do {
            g1.move();
            g2.move();
            StatMaker.processMoves(g1, g2);
            StatMaker.displayScores(g1, g2);
        }while (isGameOver == false);

        setIsGameOver(false);
        Gamer.setNumofTrials(0);
        Gamer.setNumofDraw(0);
        g1.setNumofWin(0);
        g2.setNumofWin(0);
    }

    public void startGamePvE(){
        do {
            g1.move();
            g2.moveAuto();
            System.out.println(g2.getName()+"'s choice is: " + g2.getSign());
            StatMaker.processMoves(g1, g2);
            StatMaker.displayScores(g1, g2);
        }while (isGameOver == false);

        setIsGameOver(false);
        Gamer.setNumofTrials(0);
        Gamer.setNumofDraw(0);
        g1.setNumofWin(0);
        g2.setNumofWin(0);
    }

    public void startGameEvE(){
        do {
            g1.moveAuto();
            g2.moveAuto();
            StatMaker.processMoves(g1, g2);
            isGameOver = Gamer.getNumofTrials() == 1000000;
        }while (isGameOver == false);

        StatMaker.displayScores(g1, g2);

        setIsGameOver(false);
        Gamer.setNumofTrials(0);
        Gamer.setNumofDraw(0);
        g1.setNumofWin(0);
        g2.setNumofWin(0);
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
