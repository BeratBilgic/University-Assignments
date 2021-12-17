#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int terms,i,t,k,j;

    printf("enter the number of terms\n");
    scanf("%d",&terms);
    int array[terms];
    int revArray[terms];
    printf("enter array ejements\n");
    
    for ( i = 0; i < terms; i++)
    {
        printf("array[%d] = ",i);
        scanf("%d",&array[i]);
    }
    
    t = terms-1; 
    printf("\n");

    for ( k = 0; k < terms; k++)
    {
        revArray[t] = array[k];
        t--;
    }
    for ( j = 0; j < terms; j++)
    {
        printf("array[%d] = %d\n",j,revArray[j]);
    }

    return 0;
}