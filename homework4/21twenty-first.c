// 21.Write C code to find the sum of the series 1 +11 + 111 + 1111 + .. n terms

#include <stdio.h>

int main()
{
    int terms,i,j,n,sum = 0;
    printf("enter number of terms\n");
    scanf("%d",&terms);
    
    for ( i = 1; i <= terms; i++)
    {
        n = n * 10 + 1; 
        sum = sum + n;
        printf("%d + ",n);   
    }
    printf("= %d",sum);

    return 0;
}