#include <stdio.h>

int main(){
    int a,b,c;
    printf("enter the value of a\n");
    scanf("%d",&a);
    printf("enter the value of b\n");
    scanf("%d",&b);
    printf("enter the value of c\n");
    scanf("%d",&c);
    if(a>b){
        if(a>c)
        {
        printf("%d is largest",a);
        }else
        {
        printf("%d is largest",c);  
        }
    }else if(b>c)
    {
        printf("%d is largest",b);
    }else{
        printf("%d is largest",c);
    }

    return 0;
}