package com.company;

public class StatMaker {
    public static void processMoves(Gamer g1, Gamer g2){
        if (g1.getSign() == null || g2.getSign() == null || Game.isIsGameOver())
            return;
        else if (g1.getSign() == g2.getSign())
            Gamer.setNumofDraw(Gamer.getNumofDraw() + 1);
        else if(g1.getSign() == HandSign.PAPER && g2.getSign() == HandSign.ROCK)
            g1.setNumofWin(g1.getNumofWin() + 1);
        else if(g1.getSign() == HandSign.SCISSOR && g2.getSign() == HandSign.PAPER)
            g1.setNumofWin(g1.getNumofWin() + 1);
        else if(g1.getSign() == HandSign.ROCK && g2.getSign() == HandSign.SCISSOR)
            g1.setNumofWin(g1.getNumofWin() + 1);
        else
            g2.setNumofWin(g2.getNumofWin() + 1);

        Gamer.setNumofTrials(Gamer.getNumofTrials() + 1);
    }

    public static void displayScores(Gamer g1, Gamer g2){
        System.out.println("------------------------------------------------");
        System.out.printf("%-14s%-10s%-8s%-8s%-10s\n","Gamer Name", "Trials", "Draw" ,"Win","Win rate(%)");
        System.out.printf("%-14s%-10d%-8d%-8d%-10f\n", g1.getName(), Gamer.getNumofTrials(), Gamer.getNumofDraw(),
                g1.getNumofWin(), (Gamer.getNumofTrials() < 1) ? 0 : ((float) g1.getNumofWin()/Gamer.getNumofTrials() * 100));
        System.out.printf("%-14s%-10d%-8d%-8d%-10f\n", g2.getName(), Gamer.getNumofTrials(), Gamer.getNumofDraw(),
                g2.getNumofWin(), (Gamer.getNumofTrials() < 1) ? 0 : ((float) g2.getNumofWin()/Gamer.getNumofTrials() * 100));
        System.out.println("------------------------------------------------");
    }
}
