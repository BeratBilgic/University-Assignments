// Lab 7 - The radius information and the operation type of a circle are entered from the keyboard. If the operation type is 1, the perimeter of the circle is calculated and printed, and if the operation type is 2, the area is calculated and printed.

#include <stdio.h>

int main()
{
    int r,o,area,perimeter;
    printf("enter the value of radius\n");
    scanf("%d",&r);
    printf("operation 1 = perimeter of triangle\n");
    printf("operation 2 = area of triangle\n");
    printf("choose the operation type\n");
    scanf("%d",&o);
    if (o == 1)
    {
        perimeter = 3*r*2;
        printf("perimeter of triangle  %d\n",perimeter);
    }
    else if (o == 2)
    {
        area = 3*r*r;
        printf("area of triangle  = %d\n",area);
    }
    else
    {
        printf("Wrong Input\n");
    }
    return 0;
}