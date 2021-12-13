// 24.Write C code to convert a binary number into a decimal number without using array, function and while loop.

#include <stdio.h>

int main()
{
    int num,binary,revBinary = 0,c = 1,i;
    printf("enter the number\n");
    scanf("%d",&num);

    for ( i = num; i > 0; i/=2 )
    {
        binary = i % 2;
        revBinary = revBinary + (binary * c);
        c = c * 10;
    }
    printf("%d\n",revBinary);

    return 0;
}