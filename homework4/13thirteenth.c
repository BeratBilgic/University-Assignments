// 13.Write C code to check whether a number is Strong number or not.

#include <stdio.h>

int main()
{
    int num,digit,sum = 0,fac,sameNum;
    printf("enter the number\n");
    scanf("%d",&num);
    sameNum = num;

    while (num > 0)
    {
        digit = num % 10;
        num/=10;
        fac = 1;
        for (int i = 2; i <= digit; i++)
        {
            fac = fac * i;
        }
        sum = sum + fac;
    }
    if (sameNum ==  sum)
    {
        printf("%d is strong number\n",sameNum);
    }
    else
    {
        printf("%d isn't strong number\n",sameNum);
    }

    return 0;
}