// 8. Write C code to find sum of all prime numbers between 1 to n.

#include <stdio.h>

int main()
{
    int n,check,sum = 0;
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
            sum = sum + i;
        }    
    }
    printf("\n%d is sum of the all numbers between 1 to %d\n",sum,n);
    
    return 0;
}