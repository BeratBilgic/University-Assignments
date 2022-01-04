// Homework 3 -  22.Write C code to swap first and last digits of a number.

#include <stdio.h>
#include <math.h>

int main()
{
    int last,first,number,swapNumber,digit;
    printf("enter the number\n");
    scanf("%d",&number);
    last = number % 10;
    first = number;
    digit = log10(number);

    while (first> 10)
    {
        first/=10;    
    }

    swapNumber = (last * pow(10,digit) + first) + (number - (first * pow(10,digit) + last));

    printf("new number is %d\n",swapNumber);

    return 0;
}