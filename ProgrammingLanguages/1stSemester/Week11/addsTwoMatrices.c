// Lab 11 - Write the C code that adds two matrices with the same number of rows and columns. Matrix values will be entered from the keyboard.

#include <stdio.h>

int main()
{
    int row,column;
    printf("enter the value of row\n");
    scanf("%d",&row);
    printf("enter the value of column\n");
    scanf("%d",&column);
    int a[row][column],b[row][column],c[row][column];

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("b[%d][%d] = ",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}