// Homework 3 -  6. Write C code to convert the length in feet to centimeter.

#include <stdio.h>

int main()
{
    float cm,ft;
    printf("enter the value of feet\n");
    scanf("%f",&ft);
    cm = ft*(30.48);
    printf("%f ft is %f cm",ft,cm);

    return 0;
}