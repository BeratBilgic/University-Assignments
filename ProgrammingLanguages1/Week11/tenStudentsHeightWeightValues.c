// Lab 11 - Write a program in C language that transfers the height and weight values of 10 students in a class to a two-dimensional array by reading them from the keyboard and calculates the average height and weight values and prints them on the screen.

#include <stdio.h>

int main()
{
    int s[10][2],sum1 = 0,sum2 = 0,ave1,ave2;
    printf("enter students' height and weight\n");
    for (int i = 0; i < 10; i++){
        scanf("%d\t%d",&s[i][0],&s[i][1]);
        sum1+=s[i][0];
        sum2+=s[i][1];
    }

    ave1 = sum1/10;
    ave2 = sum2/10;
    printf("average height = %d\n",ave1);
    printf("average weight = %d\n",ave2);
    
    return 0;
}