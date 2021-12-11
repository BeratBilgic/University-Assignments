// 19.Write C code to print multiplication table of any number.

#include <stdio.h>

int main()
{
    int n,product;
    printf("enter the number\n");
    scanf("%d",&n);
    printf("MULTIPLICATION TABLE OF %d\n",n);
    for (int i = 0; i <= 10; i++)
    {
        product = n * i;
        printf("%d x %d = %d\n",n,i,product);
    }
    
    return 0;
}