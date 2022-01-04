// Homework 3 -  21.Write C code to find first and last digit of a number.

#include <stdio.h>

int main()
{
    int last,first,number;
    printf("enter the number\n");
    scanf("%d",&number);
    last = number % 10;
    first = number;

    while (first> 10)
    {
        first/=10;    
    }
    printf("first digit is %d\n",first);
    printf("last digit is %d\n",last);

    return 0;
}