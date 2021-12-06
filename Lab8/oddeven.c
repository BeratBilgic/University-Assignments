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


