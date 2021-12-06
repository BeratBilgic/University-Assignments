#include <stdio.h>

int main(){
    float cm,ft;
    printf("enter the value of centimeter\n");
    scanf("%f",&cm);
    ft = cm/(30.48);
    printf("%f cm is %f ft",cm,ft);

    return 0;
}