#include <stdio.h>

int main(){
    int n;
    for ( int i = 0; i < 100; i++)
    {
        n = i*i;
        printf("%d^2 = %d\n",i,n);
    }
    
    return 0;
}