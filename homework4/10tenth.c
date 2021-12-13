// 10.Write C code to print all Armstrong numbers between 1 to n.

#include <stdio.h>
#include <math.h>

int main()
{
    int n,num,digit,digitNum,sum;
    printf("enter the value of n\n");
    scanf("%d",&n);

    for (int i = 1; i < n; i++)
    {
        digitNum = log10(i)+1;
        num = i;
        sum = 0;
        while (i)
        {
            digit = i%10;
            i/=10;
            sum = sum + pow(digit,digitNum);
        }
        
        if (sum == num)
        {      
            printf("%d is armstrong number\n",num);
        }
        i = num;
    }
    
    return 0;
}