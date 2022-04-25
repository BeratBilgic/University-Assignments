// Homework 4 - 6. Write C code to find LCM of two numbers.

#include <stdio.h>

int main()
{
    int firstNum,secondNum,largeNum,smallNum,increase;
    printf("enter the first number\n");
    scanf("%d",&firstNum);
    printf("enter the second number\n");
    scanf("%d",&secondNum);

    if (firstNum > secondNum)
    {
        largeNum = firstNum;
        smallNum = secondNum;
    }
    else
    {
        largeNum = secondNum;
        smallNum = firstNum;
    }
    increase = largeNum;

    while (largeNum > 0)
    {
        if (largeNum % smallNum == 0)
        {
            printf("%d is LCM of two numbers\n",largeNum);
            break;
        }
        largeNum = largeNum + increase;
    }

    return 0;
}