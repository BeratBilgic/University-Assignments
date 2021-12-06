#include <stdio.h>

int main()
{
    int r,o,area,perimeter;
    printf("enter the value of radius\n");
    scanf("%d",&r);
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