// Homework 4 - 4.Write C code to find the sum of the first 50 natural numbers.

#include <stdio.h>

int main()
{
    int  num,sum = 0;
 
    for (num = 1; num <= 50; num++)
    {
        sum = sum + num;
    }
    printf("Sum = %d\n", sum);

    return 0;
}
