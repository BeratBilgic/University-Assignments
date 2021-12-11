// 4. Determine Whether a Temperature is Below or Above the Freezing Point.

#include <stdio.h>

int main(){
    int a;
    printf("enter the value of temperature\n");
    scanf("%d",&a);
    if(a>0)
    {
        printf("%d above the freezing point",a);
    }else if(a<0)
    {
        printf("%d below the freezing point",a);
    }else
    {
        printf("%d is the freezing point",a);
    }

    return 0;
}