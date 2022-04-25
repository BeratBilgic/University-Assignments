#include <stdio.h>

int main(){
    double d = 5, *dp;
    dp = &d;
    int i = 5, *ip;
    ip = &i;
    float f = 5, *fp;
    fp = &f;
    char c = 'a', *cp;
    cp = &c;

    printf("double %d ",sizeof(d));
    printf("%d \n",sizeof(dp)); 
    printf("int %d ",sizeof(i));
    printf("%d \n",sizeof(ip));
    printf("float %d ",sizeof(f));
    printf("%d \n",sizeof(fp));
    printf("char %d ",sizeof(c));
    printf("%d \n",sizeof(cp));
}
