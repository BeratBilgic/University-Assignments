// Lab 8 - Calculate the area of a circle with given radius.

#include <stdio.h>

int main(){
    int r,area;
    printf("enter the value of radius\n");
    scanf("%d",&r);
    area = r*r*3;
    printf("area of triangle = %d",area);
    
    return 0;
}