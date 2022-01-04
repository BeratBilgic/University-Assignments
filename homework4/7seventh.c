// Homework 4 - 7.Write C code to print all Prime numbers between 1 to n.

#include <stdio.h>

int main()
{
    int n,check;
    printf("enter the value of n \n");
    scanf("%d",&n);
    for (int i = 2; i < n; i++)
    {
        check = 0;
        for (int j = 2; j < i; j++)
        {
            if (i%j == 0)
            {
                check++;
            }
        }
        if (check == 0)
        {
            printf("%d is prime number \n",i); 
        }    
    } 
    
    return 0;
}