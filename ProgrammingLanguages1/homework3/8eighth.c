// Homework 3 -  8. Write C code to print the SUM of numbers from LOW to HIGH. Test with LOW=3 and HIGH=9.

#include <stdio.h>

int main()
{
    int sum = 0,LOW,HIGH,i;
    i = LOW;
    printf("enter the value of LOW\n");
    scanf("%d",&LOW);
    printf("enter the value of HIGH\n");
    scanf("%d",&HIGH);
    for ( i = 1; i < HIGH; i++)
    {
        sum = sum + i;
    }
    printf("the %d of numbers from %d to %d\n",sum,LOW,HIGH);

    return 0;
}

/* 
output :
enter the value of LOW
3
enter the value of HIGH
9
the 36 of numbers from 3 to 9
*/