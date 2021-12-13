#include <stdio.h>

int main()
{
    int array[10],i,j,square;
    printf("enter 10 array elements\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d",&array[i]);
    }
    for (i = 0; i < 10; i++)
    {
        square = array[i] * array[i];
        printf("%d square = %d\n",i+1,square);
    }
    
    return 0;
}