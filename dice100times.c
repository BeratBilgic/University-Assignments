#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{  
    srand(time(0));
    int i,j,k,a,b[6];
    for ( i = 1; i <= 100; i++)
    {
        a = rand() % 6 + 1;
        for ( k = 0; k < 6; k++)
        {
            if (a == k+1)
            {
                b[k]++;
            }
        }  
    }
    for ( j = 0; j < 6; j++)
    {
        printf("%d times %d\n",b[j],j+1);
    }
    
    return 0;
}