// Homework 3 -  5. Convert Temperature from Fahrenheit (°F) to Celsius (°C).

#include <stdio.h>

int main()
{
    float c,f;
    printf("enter the value of fahrenheit\n");
    scanf("%f",&f);
    c = ((f-32)*5)/9;
    printf("%f fahrenheit(°F) = %f celsius(°C)",f,c);

    return 0;
}