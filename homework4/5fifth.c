// Homework 4 - 5.Write C code to calculate 2^4.

#include <stdio.h>

int main()
{
    int product = 1;
    for (int i = 0; i < 4; i++)
    {
        product = product*2;
    }
    printf("2^4 = %d\n",product);

    return 0;
}