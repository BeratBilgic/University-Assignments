#include <stdio.h>

int main()
{
    int a,b,sum;
    printf("enter the first number\n");
    scanf("%d",&a);
    printf("enter the second number\n");
    scanf("%d",&b);
    sum = a + b;
    printf("sum of %d and %d = %d",a,b,sum);

    return 0;
}