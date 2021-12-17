#include <stdio.h>
#include <math.h>

int main()
{
    int num,digit,b = 0,i,digitNum;
    printf("enter the number\n");
    scanf("%d",&num);
    
    digitNum = log10(num);
    int dgtary[digitNum];

    while (num > 0)
    {
        digit = num % 10;
        num /= 10;
        dgtary[b] = digit;
        b++;
    }
    printf("digits of the number :\n");
    for ( i = b-1 ; i > -1; i--)
    {
        printf("%d\n",dgtary[i]);
    }
    
    
    
    return 0;
}