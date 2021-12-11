// 17.Write C code with a natural number, n, as its input which calculates the following formula and writes the result in the standard output: S = 1⁄2 + 1⁄4 + ... +1/n.

#include <stdio.h>

int main()
{
    float sum = 0,n;
    printf("S = 1/2 + 1/4 + ... +1/n\n");
    printf("enter the value of n\n");
    scanf("%f",&n);
    for (float i = 2; i <= n; i+=2)
    {
        sum = sum + 1/i;
    }
    printf("the sum of the series = %f\n",sum);

    return 0;
}