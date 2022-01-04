// Homework 3 -  25.Write C code to find HCF (Highest Common Factor) of two numbers.

#include <stdio.h>

int main()
{
    int firstNum,secondNum,smallNum;
    printf("enter the first number\n");
    scanf("%d",&firstNum);
    printf("enter the second number\n");
    scanf("%d",&secondNum);

    if (firstNum < secondNum)
    {
        smallNum = firstNum;
    }
    else
    {
        smallNum = secondNum;
    }

    while (smallNum > 0)
    {
        if (firstNum % smallNum == 0 && secondNum % smallNum == 0 )
        {
            printf("%d is HCF (Highest Common Factor) of two numbers\n",smallNum);
            break;
        }
        smallNum--;
    }
    
    return 0;
}