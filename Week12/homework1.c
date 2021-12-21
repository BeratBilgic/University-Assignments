#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,column,v[3][3],sum,a,b;
    printf("enter the value of row\n");
    scanf("%d",&row);
    printf("enter the value of column\n");
    scanf("%d",&column);
    int f[row][column];
    int g[row-2][column-2];

    for(int i = 0 ; i < row ; i++)
    {
        for (int j = 0; j < column ; j++)
        {
            f[i][j] = rand() % 255;
            printf("%d\t",f[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("v[%d][%d] = ",i,j);
            scanf("%d",&v[i][j]);
        }
        
    }
    for (int i = 0; i < row-2; i++)
    {
        for (int j = 0; j < column-2; j++)
        {
            sum = 0;
            a = 0;
            for ( int k = i; k < i+3; k++)
            {
                b = 0;
                for (int l = j; l < j+3; l++)
                {
                    sum = sum + (f[k][l] * v[a][b]);
                    b++;
                }
                a++;
            }
            g[i][j] = sum;
            printf("%d\t",g[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}