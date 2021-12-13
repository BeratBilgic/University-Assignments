// 19.Write C code to display the sum of the series [ 1+x+x^2/2!+x^3/3!+....].

#include <stdio.h>
#include <math.h>

int main()
{
    float x,n,p;
    float fac = 1, sum = 1;
    printf("Enter the value of x\n");
    scanf("%f",&x);
    printf("Enter the value of n\n");
    scanf("%f",&n);
    
    for (float i = 1; i < n; i++)
    {    
        p = pow(x,i);
        fac = fac*i;
        sum = sum + (p/fac);
    }
    printf("The sum of the series = %f\n",sum);

    return 0;
}