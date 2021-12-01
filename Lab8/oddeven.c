#include <stdio.h>

int main(){
    int a,b;
    printf("Bir sayı giriniz");
    scanf("%d",&a);
    b = a%2;
    if( b == 0){
        printf("%d çift",a);
    }else{
        printf("%d tek",a);
    }
    return 0;
}


