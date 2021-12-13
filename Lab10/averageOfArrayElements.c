#include <stdio.h>

int main()
{
    int array[8],i,sum = 0,average;
    for ( i = 0; i < 8; i++)
    {
        printf("enter 8 array elements\n");
        scanf("%d",&array[i]);   
    }
    for ( i = 0; i < 8; i++)
    {
        sum = sum + array[i];
    }
    average = sum/8;

    printf("sum of the array elements = %d\n",average);

    return 0;
}