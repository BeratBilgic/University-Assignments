package com.company;

public class Main {

    public static void main(String[] args) {
        Cat cat = new Cat();
        Eagle eagle = new Eagle();
        Duck duck = new Duck();

        Animal[] animals = {cat, eagle, duck};

        System.out.println("\n---Swimming Animals");
        for(Animal animal : animals){
            if (animal instanceof Swimmable){
                ((Swimmable)animal).swim();
            }
        }

        System.out.println("\n---Moving Animals");
        for(Animal animal : animals){
            if (animal instanceof Moveable){
                ((Moveable)animal).move();
            }
        }

        System.out.println("\n---Flying Animals");
        for(Animal animal : animals){
            if (animal instanceof Flyable){
                ((Flyable)animal).fly();
            }
        }
    }
}
