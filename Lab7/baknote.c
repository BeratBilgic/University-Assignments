#include <stdio.h>

int main()
{
    int money,a,b,c,d;
    printf("enter the amount of money\n");
    scanf("%d",&money);
    printf("baknote\tamount\n");
    a = money/100;
    money%=100;
    printf("100 \t %d\n",a);
    b = money/50;
    money%=50;
    printf("50  \t %d\n",b);
    c = money/20;
    money%=20;
    printf("20  \t %d\n",c);
    d = money/10;
    printf("10  \t %d\n",d);
    return 0;
}
/*
output:
enter the amount of money
460
baknote amount
100      4
50       1
20       0
10       1
*/