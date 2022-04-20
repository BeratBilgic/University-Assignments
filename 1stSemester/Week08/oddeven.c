// Lab 8 - Determine and Output Whether Number N is Even or Odd.

#include <stdio.h>

int main(){
    int a,b;
    printf("enter the number\n");
    scanf("%d",&a);
    b = a%2;
    if( b == 0){
        printf("%d is even",a);
    }else{
        printf("%d is odd",a);
    }
    return 0;
}