// Lab 8 - Write C code to print the square of all numbers from 1 to10.

#include <stdio.h>

int main(){
    int n;
    for ( int i = 0; i < 10; i++)
    {
        n = i*i;
        printf("%d^2 = %d\n",i,n);
    }
    
    return 0;
}