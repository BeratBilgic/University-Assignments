// Homework 4 - 24.Write C code to convert a binary number into a decimal number without using array, function and while loop.

#include <stdio.h>
#include <math.h>

int main()
{
    int binaryNum,binary,num = 0,i,a,digitNum;
    printf("enter a binary number = ");
    scanf("%d",&binaryNum);

    digitNum = log10(binaryNum);
    a = pow(10,digitNum);

    for (i = 0; i <= digitNum; i++)
    {
        binary = binaryNum / a;
        binaryNum %= a;
        num = (num * 2) + binary;
        a/=10;
    }
    
    printf("equivalent decimal number is = %d \n", num);

    return 0;
}