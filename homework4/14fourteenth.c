// 14.Write C code to print all Strong numbers between 1 to n.

#include <stdio.h>

int main()
{
    int n,digit,fac,sum,num;
    printf("enter the value of n\n");
    scanf("%d",&n);

    for (int i = 1; i < n; i++)
    {
        num = i;
        sum = 0;
        while (num > 0)
        {
            digit = num % 10;
            num/=10;
            fac = 1;
            for (int j = 2; j <= digit; j++)
            {
               fac = fac * j;
            }
            sum = sum + fac;
        }
        if ( i == sum)
        {
            printf("%d is strong number\n",i);
        }
    }

    return 0;
}