// Homework 4 - 25.Write C code to print Pascal triangle upto n rows.

#include <stdio.h>

int main()
{
    long int i,j,row,k,a,b,faci=1,facj=1,output;
    printf("Enter number of rows\n");
    scanf("%ld",&row);

    for ( i = 0; i <= row; i++){
        for (k = 0; k < row-i; k++){
            printf("  ");
        }
        
        for ( j = 0; j <= i; j++){
            faci=1;
            facj=1;
            for (a = i; a > i-j ;a--){
                faci = faci * a;
            }
            for ( b = j ; b > 1; b--){
                facj = facj * b;
            }
            output = faci / facj;
            printf("    %ld",output);
        }
        printf("\n");
    }
    
    return 0;
}