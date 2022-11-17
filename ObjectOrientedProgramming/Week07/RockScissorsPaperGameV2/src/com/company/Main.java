package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Gamer g1 = new Gamer("Gamer1");
        Gamer g2 = new Gamer("Gamer2");
        Gamer pc1 = new Gamer("PC1");
        Gamer pc2 = new Gamer("PC2");
        Game game;

        Scanner scanner = new Scanner(System.in);

        while (true){
            System.out.println("\n1 - PvP\n2 - PvE\n3 - EvE\n0 - Exit");
            int key = scanner.nextInt();

            switch (key){
                case 1:
                    game = new Game(g1,g2);
                    game.startGamePvP();
                    break;
                case 2:
                    game = new Game(g1,pc1);
                    game.startGamePvE();
                    break;
                case 3:
                    game = new Game(pc1,pc2);
                    game.startGameEvE();
                    break;
                default:
                    return;
            }
        }
    }
}
