// 11.Write C code for a program that reads 10 numbers from the user and prints out their sum, and their product.

#include <stdio.h>

int main()
{
    int sum = 0,product = 1,n;
    for (int i = 0; i < 10; i++)
    {
        printf("enter the number\n");
        scanf("%d",&n);
        sum = sum + n;
        product = product * n;
    }
    printf("the sum of 10 numbers = %d\n",sum);
    printf("the product of 10 numbers = %d\n",product);

    return 0;
}