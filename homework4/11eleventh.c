// 11.Write C code to check whether a number is Perfect number or not.

#include <stdio.h>

int main()
{
    int num,i,sum = 0;
    printf("enter the number\n");
    scanf("%d",&num);

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
    else
    {
        printf("%d isn't perfect number\n",num);
    }
    
    return 0;
}