package com.company;

public class U2 extends Rocket{
    //U-2
    //Rocket cost = $120 Million
    //Rocket weight = 18 Tonnes
    //Max weight (with cargo) = 29 Tonnes
    //Chance of launch explosion = 4% * (cargo carried / cargo limit)
    //Chance of landing crash = 8% * (cargo carried / cargo limit)
    public U2() {
        super(120, 18000, 29000, 18000);
    }

    @Override
    public boolean launch() {
        double cargoCarried = getCurrentWeight() - getWeight();
        double cargoLimit = getMaxWeight() - getWeight();
        setChanceOfLaunchExplosion(0.04 * (cargoCarried / cargoLimit));
        return getChanceOfLaunchExplosion() <= Math.random();
    }

    @Override
    public boolean land() {
        double cargoCarried = getCurrentWeight() - getWeight();
        double cargoLimit = getMaxWeight() - getWeight();
        setChanceOfLandingCrash(0.08 * (cargoCarried / cargoLimit));
        return getChanceOfLandingCrash() <= Math.random();
    }
}
