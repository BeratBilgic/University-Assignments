// Homework 4 - 1. Write C code that will read the two sides of a rectangle and calculate its area and perimeter.

#include <stdio.h>

int main()
{
    int a,b,area,perimeter;
    printf("enter the value of first side of a rectangle\n");
    scanf("%d",&a);
    printf("enter the value of second side of a rectangle\n");
    scanf("%d",&b);
    area = a*b;
    perimeter = 2*(a+b);
    printf("area of a rectangle = %d\n",area);
    printf("perimeter of a rectangle = %d\n",perimeter);

    return 0;
}