// 1. Write C code to add two numbers entered by user.

#include <stdio.h>

int main()
{
    int a,b,sum;
    printf("enter the first number\n");
    scanf("%d",&a);
    printf("enter the second number\n");
    scanf("%d",&b);
    sum = a + b;
    printf("sum of two numbers = %d\n",sum);
    
    return 0;
}