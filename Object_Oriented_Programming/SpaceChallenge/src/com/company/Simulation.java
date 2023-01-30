package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Simulation {
    public ArrayList<Item> loadItems(String filePath) throws FileNotFoundException {
        ArrayList<Item> items = new ArrayList<>();

        File file = new File(filePath);
        Scanner fileScanner = new Scanner(file);
        String[] fileItem;

        while (fileScanner.hasNextLine()) {
            Item item = new Item();
            fileItem = fileScanner.nextLine().split("=");
            item.setName(fileItem[0]);
            item.setWeight(Integer.parseInt(fileItem[1]));
            items.add(item);
        }
        fileScanner.close();

        return items;
    }

    public ArrayList<Rocket> loadU1(ArrayList<Item> loadItems){
        ArrayList<Rocket> u1Rockets = new ArrayList<>();
        Rocket u1Rocket = new U1();

        for (Item item: loadItems) {
            if (u1Rocket.canCarry(item)){
                u1Rocket.carry(item);
            }
            else {
                u1Rockets.add(u1Rocket);
                u1Rocket = new U1();
                u1Rocket.carry(item);
            }
        }
        if (u1Rockets.size() != 0) {
            u1Rockets.add(u1Rocket);
        }

        return u1Rockets;
    }

    public ArrayList<Rocket> loadU2(ArrayList<Item> loadItems){
        ArrayList<Rocket> u2Rockets = new ArrayList<>();
        Rocket u2Rocket = new U2();

        for (Item item: loadItems) {
            if (u2Rocket.canCarry(item))
                u2Rocket.carry(item);
            else {
                u2Rockets.add(u2Rocket);
                u2Rocket = new U2();
                u2Rocket.carry(item);
            }
        }
        if (u2Rockets.size() != 0) {
            u2Rockets.add(u2Rocket);
        }

        return u2Rockets;
    }

    public int runSimulation(ArrayList<Rocket> rockets){
        int totalBudget = 0;
        for (Rocket rocket: rockets) {
            do {
                totalBudget+=rocket.getCost();
            } while (!(rocket.launch() && rocket.land()));
        }

        return  totalBudget;
    }
}
