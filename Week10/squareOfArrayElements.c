#include <stdio.h>

// Lab 10 - Write a program that transfers the numbers given until -1 is entered from the keyboard, and then prints the square of each element to the screen. (The number of array elements will be maximum 10.)

int main()
{
    int array[10],i,j,square,num;
    printf("enter 10 array elements\n");

    for (i = 0; i < 10; i++){
        scanf("%d",&array[i]);
        if (array[i] == -1){
            break;
        }     
    }
    for (i = 0; i < 10; i++){
        if (array[i] == -1){
            break;
        }else
        {
            square = array[i] * array[i];
            printf("%d square = %d\n",array[i],square);
        }
    }
    
    return 0;
}