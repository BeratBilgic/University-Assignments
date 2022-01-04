// Homework 3 -  23.Write C code to check whether a number is palindrome or not.

#include <stdio.h>

int main()
{
    int digit,number,sameNumber,reverseNumber = 0;
    printf("enter the number\n");
    scanf("%d",&number);
    sameNumber = number;

    while (number> 0)
    {
        digit = number % 10;
        number/=10; 
        reverseNumber = reverseNumber*10 + digit;   
    }
    if (sameNumber == reverseNumber)
    {
        printf("%d is a palindrome number\n",sameNumber);
    }
    else
    {
        printf("%d isn't a palindrome number\n",sameNumber);
    }
    

    return 0;
}