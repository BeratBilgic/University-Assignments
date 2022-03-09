#include <stdio.h>

int main(){
    int a,b,sum,*ap,*bp;
    a = 5;
    b = 6;
    ap = &a;
    bp = &b;
    sum = *ap + *bp;
    printf("%d",sum);
}