// Lab 10 - Write a program that takes a 10-element array from the keyboard and writes it in reverse to the screen. (1.5,2,4,5,6,78,12,1.3 => 3.1,12,78,6,5,4,2,5,1)

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
    
    for ( i = 0; i < terms; i++){
        printf("array[%d] = ",i);
        scanf("%d",&array[i]);
    }
    
    t = terms-1; 
    printf("\n");

    for ( k = 0; k < terms; k++){
        revArray[t] = array[k];
        t--;
    }
    for ( j = 0; j < terms; j++){
        printf("array[%d] = %d\n",j,revArray[j]);
    }

    return 0;
}