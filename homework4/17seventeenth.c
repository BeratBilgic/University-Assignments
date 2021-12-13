// 17.Write C code to display the n terms of harmonic series and their sum. (1 + 1/2 + 1/3 + 1/4 + 1/5 ... 1/n terms)

#include <stdio.h>

int main()
{
    float n,sum = 0;
    printf("enter the value of n\n");
    scanf("%f",&n);
    
    for (float i = 1; i <= n; i++)
    {
        sum = sum + 1/i;
    }
    printf("the sum of the series = %f\n",sum);

    return 0;
}