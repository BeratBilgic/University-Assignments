// Homework 4 - 12.Write C code to print all Perfect numbers between 1 to n.

#include <stdio.h>

int main()
{
    int n,num,i,sum;
    printf("enter the value of n\n");
    scanf("%d",&n);

    for ( num = 1; num < n; num++)
    {
        sum = 0;
        for ( i = 1; i < num; i++)
        {
            if (num % i == 0)
            {
                sum = sum + i;
            }
        }
        if (num == sum)
        {
            printf("%d is perfect number\n",num);
        }
    }
    
    return 0;
}