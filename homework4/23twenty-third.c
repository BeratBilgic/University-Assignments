// 23.Write C code to convert a decimal number into binary without using an array.

#include <stdio.h>

int main()
{
    int num,binary,revBinary = 0,c = 1;
    printf("enter the number\n");
    scanf("%d",&num);

    while ( num > 0 )
    {
        binary = num % 2;
        num/=2;
        revBinary = revBinary + (binary * c);
        c = c * 10;
    }
    printf("%d\n",revBinary);

    return 0;
}