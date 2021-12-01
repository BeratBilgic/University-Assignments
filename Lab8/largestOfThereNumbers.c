#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a>b){
        if(a>c)
        {
        printf("en büyük %d",a);
        }else{
        printf("en büyük %d",c);  
        }
    }else if(b>c){
        printf("en büyük %d",b);
    }else{
        printf("en büyük %d",c);
    }

    return 0;
}