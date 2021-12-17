#include <stdio.h>

int main()
{
    float array[8],sum = 0,average;
    printf("enter 8 array elements\n");

    for (int i = 0; i < 8; i++)
    {
        scanf("%f",&array[i]); 
        sum = sum + array[i];  
    }
    average = sum/8;

    printf("average of the array elements = %f\n",average);

    return 0;
}