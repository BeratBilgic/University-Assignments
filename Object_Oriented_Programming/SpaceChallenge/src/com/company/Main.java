package com.company;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        String phase1filePath = "textFiles/phase-1.txt";
        String phase2filePath = "textFiles/phase-2.txt";

        ArrayList<Item> phase1Items = new ArrayList<>();
        ArrayList<Item> phase2Items = new ArrayList<>();
        Simulation simulation = new Simulation();

        try {
            phase1Items = simulation.loadItems(phase1filePath);
            phase2Items = simulation.loadItems(phase2filePath);
        }catch (FileNotFoundException e){
            System.out.println("error -> " + e.getMessage());
        }

        ArrayList<Rocket> fleetOfU1Phase1 = simulation.loadU1(phase1Items);
        ArrayList<Rocket> fleetOfU1Phase2 = simulation.loadU1(phase2Items);

        int budgetU1phase1 = 0, budgetU1phase2 = 0;
        budgetU1phase1 = simulation.runSimulation(fleetOfU1Phase1);
        budgetU1phase2 = simulation.runSimulation(fleetOfU1Phase2);
        System.out.println("Budget of U1 fleet for phase 1 = $" + budgetU1phase1
                + " Million for " + fleetOfU1Phase1.size() + " U1 rockets");
        System.out.println("Budget of U1 fleet for phase 2 = $" + budgetU1phase2
                + " Million for " + fleetOfU1Phase2.size() + " U1 rockets");
        System.out.println("Total budget of U1 fleet = $" + (budgetU1phase1 + budgetU1phase2) + " Million\n");

        ArrayList<Rocket> fleetOfU2Phase1 = simulation.loadU2(phase1Items);
        ArrayList<Rocket> fleetOfU2Phase2 = simulation.loadU2(phase2Items);

        int budgetU2phase1 = 0, budgetU2phase2 = 0;
        budgetU2phase1 = simulation.runSimulation(fleetOfU2Phase1);
        budgetU2phase2 = simulation.runSimulation(fleetOfU2Phase2);
        System.out.println("Budget of U2 fleet for phase 1 = $" + budgetU2phase1
                + " Million for " + fleetOfU2Phase1.size() + " U2 rockets");
        System.out.println("Budget of U2 fleet for phase 2 = $" + budgetU2phase2 +
                " Million for " + fleetOfU2Phase2.size() + " U2 rockets");
        System.out.println("Total budget of U2 fleet = $" + (budgetU2phase1 + budgetU2phase2) + " Million\n");
    }
}
