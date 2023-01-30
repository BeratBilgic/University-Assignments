package com.company;

public class U1 extends Rocket{
    //U-1
    //Rocket cost = $100 Million
    //Rocket weight = 10 Tonnes
    //Max weight (with cargo) = 18 Tonnes
    //Chance of launch explosion = 5% * (cargo carried / cargo limit)
    //Chance of landing crash = 1% * (cargo carried / cargo limit)
    public U1() {
        super(100, 10000, 18000, 10000);
    }

    @Override
    public boolean launch() {
        double cargoCarried = getCurrentWeight() - getWeight();
        double cargoLimit = getMaxWeight() - getWeight();
        setChanceOfLaunchExplosion(0.05 * (cargoCarried / cargoLimit));
        return getChanceOfLaunchExplosion() <= Math.random();
    }

    @Override
    public boolean land() {
        double cargoCarried = getCurrentWeight() - getWeight();
        double cargoLimit = getMaxWeight() - getWeight();
        setChanceOfLandingCrash(0.01 * (cargoCarried / cargoLimit));
        return getChanceOfLandingCrash() <= Math.random();
    }
}
