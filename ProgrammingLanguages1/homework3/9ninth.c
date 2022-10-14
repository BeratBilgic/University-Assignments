// Homework 3 -  9. Write C code to print all numbers between LOW and HIGH that are divisible by NUMBER.

#include <stdio.h>

int main()
{
    int NUMBER,LOW,HIGH,i;
    printf("enter the value of LOW\n");
    scanf("%d",&LOW);
    printf("enter the value of HIGH\n");
    scanf("%d",&HIGH);
    printf("enter the value of NUMBER\n");
    scanf("%d",&NUMBER);
    i = LOW;
    for ( i = 1; i < HIGH; i++)
    {
        if (i%NUMBER == 0)
        {
            printf("%d are divisible by %d\n",i,NUMBER);
        }
    }

    return 0;
}