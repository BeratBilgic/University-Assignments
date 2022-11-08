package com.company;

public class Main {

    public static void main(String[] args) {
        Gamer g1 = new Gamer("Gamer1");
        Gamer g2 = new Gamer("Gamer2");
        Game game = new Game(g1, g2);
        game.startGame();
    }
}
