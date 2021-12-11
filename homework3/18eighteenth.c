// 18.Write C code to convert a decimal number, n, to binary format?

#include <stdio.h>

int main(){

    int n,i,binary;
    int m[20];
    scanf("%d",&n);

    for (i = 0; n>0; i++)
    {   
        binary = n % 2 ;
        n = n/2;
        m[i] = binary;
    }
    for ( i = i-1; i >= 0; i--)
    {
        printf("%d",m[i]);
    }
    
return 0;
}