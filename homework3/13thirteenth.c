// Homework 3 -  13.Write C code to print the multiplication table for 6's.

#include <stdio.h>

int main()
{
    int product;
    for (int i = 0; i <= 10; i++)
    {
        product = 6*i;
        printf("6 x %d = %d\n",i,product);
    }
    
    return 0;
}