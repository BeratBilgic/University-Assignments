// 16.Write C code to find the sum of the series [ 1-X^2/2!+X^4/4!- .........].

#include <stdio.h>
#include <math.h>

int main()
{
    float x,n,p;
    float fac = 1, sum = 1, m = -1;
    printf("Enter the value of x\n");
    scanf("%f",&x);
    printf("enter number of terms\n");
    scanf("%f",&n);
    
    for (float i = 2; i < n*2; i+=2)
    {   
        p = pow(x,i);
        p = p*m;
        fac = fac * i * (i-1);
        sum = sum + (p/fac);
        m = m * -1;
    }
    printf("The sum of the series = %f\n",sum);

    return 0;
}