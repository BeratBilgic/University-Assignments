// 20.Write C code to find the sum of the series [ x - x^3 + x^5 + ......].

#include <stdio.h>
#include <math.h>

int main()
{
    int n,i,x,sum = 0,p,m = 1;
    printf("enter the value of x\n");
    scanf("%d",&x);
    printf("enter number of terms\n");
    scanf("%d",&n);

    for (i = 1; i <= n*2; i+=2)
    {
        p = pow(x,i);
        p = p * m;
        sum = sum + p;
        m = m * -1;
    }
    printf("The sum of the series = %d\n",sum); 
    
    return 0;
}