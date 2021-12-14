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
    t = terms-1;
    
    for ( i = 0; i < terms; i++)
    {
        printf("array[%d] = ",i);
        scanf("%d",&array[i]);
    }
    printf("\n");

    for ( i = terms-1; i > -1; i--)
    {
        printf("array[%d] = %d\n",i,array[i]);
    }
    

    /*for ( k = 0; k < terms; k++)
    {
        printf("%d\n",array[k]);
        revArray[t] = array[k];
        t--;
    }
    for ( j = 0; j < terms; j++)
    {
        printf("array[%d] = %d\n",j,revArray[j]);
    }*/
    

    return 0;
}