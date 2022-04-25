// Homework 3 -  15.Write C code to print all natural numbers in reverse (from n to 1).

#include <stdio.h>

int main()
{
    int n,i;
    printf("enter the value of n\n");
    scanf("%d",&n);
    i = n;
    while ( i > 0 )
    {
        printf("%d\n",i);
        i--;
    }

    return 0;
}