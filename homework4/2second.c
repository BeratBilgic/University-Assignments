// 2. Write C code to find all the roots of a quadratic equation ax2+bx+c=0.

#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c,delta,x1,x2;
    printf("enter the value of a \n");
    scanf("%f",&a);
    printf("enter the value of b \n");
    scanf("%f",&b);
    printf("enter the value of c \n");
    scanf("%f",&c);
    delta = (b*b)-(4*a*c);
    if (delta < 0)
    {
        printf("the equation has no root\n");
    }
    else if(delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("the roots of the equation are %f and %f\n",x1,x2);
    }
    else
    {
        x1 = (-b + sqrt(delta)) / (2*a);
        printf("the roots of the equation are %f\n",x1);
    }

    return 0;
}