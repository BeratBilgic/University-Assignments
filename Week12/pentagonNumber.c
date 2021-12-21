#include <stdio.h>

int main()
{
    for (float i = 1; i <= 100; i++)
    {
        float p = i*(3*i-1)/2;
        printf("%f\n",p);
    }
    
    return 0;
}