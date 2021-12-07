#include <stdio.h>
#include <math.h>

int main()
{
    float x,n,fac = 1,sum = 0,p;
    scanf("%f",&x);
    scanf("%f",&n);
    
    for (float i = 1; i < n; i++)
    {
        p = pow(x,i);
        fac = fac*i;
        sum = sum + (p/fac);
    }
    sum = sum + 1;
    printf("%f",sum);

    return 0;
}