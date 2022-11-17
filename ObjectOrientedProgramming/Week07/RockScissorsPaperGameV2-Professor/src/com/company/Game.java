package com.company;

public class Game {
    Gamer gamer1;
    Gamer gamer2;
    static boolean isGameOver;

    Game(Gamer gamer1, Gamer gamer2){
        this.gamer1 = gamer1;
        this.gamer2 = gamer2;
    }

    void start(){
        do{
            gamer1.moveAutomatic();
            gamer2.moveAutomatic();
            processMovements();
            isGameOver = (Gamer.numberOfTrials == 1000000); // to stop PC vs PC
        }while(!isGameOver);

        displayScores(gamer1);
        displayScores(gamer2);
    }

    void processMovements(){
        if (gamer1 ==null  || gamer2 == null || isGameOver) return;
        else if(gamer1.handSign == gamer2.handSign)
            Gamer.numberofDraws++;
        else if(gamer1.handSign == HandSign.PAPER && gamer2.handSign == HandSign.ROCK)
            gamer1.numberofWins++;
        else if(gamer1.handSign == HandSign.SCISSOR && gamer2.handSign == HandSign.PAPER)
            gamer1.numberofWins++;
        else if(gamer1.handSign == HandSign.ROCK && gamer2.handSign == HandSign.SCISSOR)
            gamer1.numberofWins++;
        else
            gamer2.numberofWins++;

        Gamer.numberOfTrials++;
    }

    private void displayScores(Gamer gamer) {
        String gamerData = String.format(" gamer:%s number of wins: " +
                "%d number of draws: %d number of trials %d",
                gamer.name, gamer.numberofWins, Gamer.numberofDraws, Gamer.numberOfTrials);
        System.out.println(gamerData);
    }
}
