// Lab 13 - The 10-element integer array will be sent to a function by entering values from the keyboard. Write a function that finds the "biggest first two numbers" in the array and prints it to the screen.

#include <stdio.h>

#define g 10

int biggest(int arr[]);

int main()
{
    int input[g],n1,n2;
    printf("enter 10 array elements\n");
    for (int i = 0; i < g; i++){
        scanf("%d",&input[i]);
    } 
    n1 = biggest(input);
    n2 = biggest(input);
    printf("\nBiggest first two numbers = %d and %d \n",n1,n2);
    
    return 0;
}
int biggest(int arr[])
{
    int max = 0;
    for (int i = 0; i < g; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    for (int j = 0; j < g; j++){
        if (arr[j] == max){
            arr[j] = 0;
        }  
    }
    return max; 
}