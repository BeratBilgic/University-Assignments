#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{  
    srand(time(0));
    int i,j,counter[6],diceData[100],a;
    for ( i = 0; i < 100; i++)
    {
        diceData[i]  = rand() % 6 + 1;
        a = diceData[i]-1;
        counter[a]++;
    }
    for ( j = 0; j < 6; j++)
    {
        printf("%d times %d\n",counter[j],j+1);
    }
    
    return 0;
}