package com.company;

public class Main {
    public static void main(String[] args) {

        Gamer gamer1 = new Gamer("PC_1");
        Gamer gamer2 = new Gamer("PC_2");
        Game game = new Game(gamer1, gamer2);
        game.start();
    }
}