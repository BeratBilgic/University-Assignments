// Lab 10 - Enter a value from the keyboard to the 8-element float array. Calculate the average of the entered values and print it on the screen.

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