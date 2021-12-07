#include <stdio.h>
#include <math.h>

int main()
{
    float x,n,p;
    float fac = 1, sum = 1;
    scanf("%f",&x);
    scanf("%f",&n);
    
    for (float i = 1; i < n; i++)
    {
        p = pow(x,i);
        fac = fac*i;
        sum = sum + (p/fac);
    }
    printf("%f",sum);

    return 0;
}