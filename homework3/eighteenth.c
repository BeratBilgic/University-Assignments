#include <stdio.h>

int main(){

    int n,i,binary,count = 0;
    int m[20];
    scanf("%d",&n);
    
    for (i = 0; i < 20; i++)
    {   
        binary = n % 2 ;
        n = n/2;
        m[i] = binary;
        count++;
    }
    for ( i = count; i > 0; i--)
    {
        printf("%d",m[i]);
    }
    
return 0;
}