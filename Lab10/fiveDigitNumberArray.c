#include <stdio.h>
#include <math.h>

int main()
{
    int num,digit,b,i,digitNum;
    scanf("%d",&num);
    b=0;
    digitNum = log10(num);
    int dgtary[digitNum];

    while (num>0)
    {
        digit = num % 10;
        num /= 10;
        dgtary[b] = digit;
        b++;
    }
    for ( i = b-1 ; i > -1; i--)
    {
        printf("%d\n",dgtary[i]);
    }
    
    
    
    return 0;
}