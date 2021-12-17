#include <stdio.h>

int main()
{
    int num,controlNum,digit,num1 = 0;
    printf("enter the number\n");
    scanf("%d",&num);
    controlNum = num;
    while(num > 0)
    {
        digit = num%10;
        num = num/10;
        num1 = num1*10 + digit;
    }
    if (num1 == controlNum)
    {
        printf("%d is palindrome",num1);
    }else
    {
        printf("%d isn't palindrome",num1);
    }
    

    return 0;
}