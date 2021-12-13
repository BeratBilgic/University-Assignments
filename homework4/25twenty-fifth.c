// 25.Write C code to print Pascal triangle upto n rows.
// It works up to rows 13

#include <stdio.h>

int main()
{
    int i,j,row,k,ii,jj,faci=1,facj=1,output;
    printf("Enter number of rows\n");
    scanf("%d",&row);

    for ( i = 0; i <= row; i++)
    {
        for (k = 0; k < row-i; k++)
        {
            printf("  ");
        }
        
        for ( j = 0; j <= i; j++)
        {
            faci=1;
            facj=1;
            for (ii = i; ii > i-j ;ii--)
            {
                faci = faci * ii;
            }
            for ( jj = j ; jj > 1; jj--)
            {
                facj = facj * jj;
            }
            output = faci / facj;
            printf("    %d",output);
        }
        printf("\n");
    }
    
    return 0;
}