// Homework 3 -  24.Write C code to find frequency of each digit in a given integer.

#include <stdio.h>

int main()
{
    int number,count,digit,sameNumber;
    printf("enter the number\n");
    scanf("%d",&number);
    sameNumber = number;
    
    for (int i = 0; i < 10; i++)
    {
        count = 0;
        number = sameNumber;

        while (number > 0)
        {
            digit = number % 10;

            if (i == digit)
            {
                count++;
            }
            number/=10;
        }
        printf("The frequency of %d = %d\n",i,count);
    }
    
    return 0;
}