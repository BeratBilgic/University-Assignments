// 9. Write C code to check whether a number is Armstrong number or not.

#include <stdio.h>
#include <math.h>

int main()
{
    int num,digit,sameNum,digitNum,sum = 0;
    printf("enter the number\n");
    scanf("%d",&num);
    digitNum = log10(num)+1;
    sameNum = num;
    
    while (num > 0)
    {
        digit = num % 10;
        num/=10;
        sum = sum + pow(digit,digitNum);
    }
    if (sum == sameNum)
    {
        printf("%d is armstrong number",sameNum);
    }
    else
    {
        printf("%d isn't armstrong number",sameNum);
    }
    
    return 0;
}