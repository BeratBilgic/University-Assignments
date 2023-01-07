package com.company;

public class Rocket implements SpaceShip{
    private int cost;
    private int weight;
    private int maxWeight;
    private int currentWeight; //with cargo
    private double chanceOfLaunchExplosion;
    private double chanceOfLandingCrash;

    public Rocket(int cost, int weight, int maxWeight, int currentWeight) {
        this.cost = cost;
        this.weight = weight;
        this.maxWeight = maxWeight;
        this.currentWeight = currentWeight;
    }

    @Override
    public boolean launch() {
        return true;
    }

    @Override
    public boolean land() {
        return true;
    }

    @Override
    public boolean canCarry(Item item) {
        return (currentWeight + item.getWeight()) <= maxWeight;
    }

    @Override
    public void carry(Item item) {
        currentWeight+=item.getWeight();
    }

    public int getCost() {
        return cost;
    }

    public int getWeight() {
        return weight;
    }

    public int getMaxWeight() {
        return maxWeight;
    }

    public int getCurrentWeight() {
        return currentWeight;
    }

    public double getChanceOfLaunchExplosion() {
        return chanceOfLaunchExplosion;
    }

    public void setChanceOfLaunchExplosion(double chanceOfLaunchExplosion) {
        this.chanceOfLaunchExplosion = chanceOfLaunchExplosion;
    }

    public double getChanceOfLandingCrash() {
        return chanceOfLandingCrash;
    }

    public void setChanceOfLandingCrash(double chanceOfLandingCrash) {
        this.chanceOfLandingCrash = chanceOfLandingCrash;
    }

    @Override
    public String toString() {
        return "Rocket{" +
                "cost=" + cost +
                ", weight=" + weight +
                ", maxWeight=" + maxWeight +
                ", currentWeight=" + currentWeight +
                ", chanceOfLaunchExplosion=" + chanceOfLaunchExplosion +
                ", chanceOfLandingCrash=" + chanceOfLandingCrash +
                '}';
    }
}
