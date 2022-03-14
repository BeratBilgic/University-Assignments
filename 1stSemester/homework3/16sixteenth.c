// Homework 3 -  16.Write C code which generates even numbers between 1000 and 2000 and then prints them in the standard output. It should also print total sum.

#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i = 1000; i < 2000; i+=2)
    {
        printf("%d\t",i);
        sum = sum + i;
    }
    printf("\nThe sum of all even numbers between 1000 and 2000 = %d\n",sum);

    return 0;
}