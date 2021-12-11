// 20.Write C code to count number of digits in a number.

#include <stdio.h>

int main()
{
    long int number,count = 0,samenumber;
    printf("enter the number\n");
    scanf("%ld",&number);
    samenumber = number;
    while ( number > 0 )
    {
        number/=10;
        count++;
    }
    printf("%ld digits in %ld\n",count,samenumber);

    return 0;
}