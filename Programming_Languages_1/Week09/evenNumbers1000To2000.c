// Lab 9 - Write a C program which generates even numbers between 1000 and 2000 and then prints them.

#include <stdio.h>

int main()
{
    printf("EVEN NUMBERS BETWEEN 1000 TO 2000\n");
    for (int i = 1000; i <= 2000; i+=2)
    {    
        printf("%d\t",i);   
    }

    return 0;
}