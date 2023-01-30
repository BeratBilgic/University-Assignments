package com.company;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionHandlingLabExercise {

    public static void runExceptionHandlingLabExercise(){
        int value;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        try {
            value = scanner.nextInt();
        }catch (InputMismatchException e){
            System.out.println(e);
        }
    }
}
/*
You need to read an integer value from keyboard. However, let's say a user typed a string value.
This will cause an input mismatch exception.
Handle this exception.
(Hint: use InputMismatchException exception.)
 */
