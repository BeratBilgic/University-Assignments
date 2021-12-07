#include <stdio.h>

int main()
{
    int fac,n;
    printf("enter a number to calculate its factorial\n");
    scanf("%d",&fac);
    n = fac;
    for (int i = 2; i < n; i++)
    {
        fac = fac * i;
    }
    printf("%d factorial = %d\n",n,fac); 

    return 0;
}