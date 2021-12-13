// 22.Write C code to find the number and sum of all integer between 100 and 200 which are divisible by 9.

#include <stdio.h>

int main()
{
    int i,sum = 0;
    for ( i = 108; i < 200; i+=9)
    {
        printf("%d is divisible by 9\n",i);
        sum = sum + i;
    }
    printf("\n%d sum of all integer between 100 and 200 which are divisible by 9\n",sum);
    
    return 0;
}