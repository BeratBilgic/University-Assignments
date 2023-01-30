// Lab 8 - Convert Temperature from Fahrenheit (°F) to Celsius (°C).

#include <stdio.h>

int main(){
    float c,f;
    printf("enter the value of celsius\n");
    scanf("%f",&c);
    f = c*9/5 + 32;
    printf("%f celsius = %f fahrenheit",c,f);
    return 0;
}