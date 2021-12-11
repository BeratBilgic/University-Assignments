// 10.Write C code to find the largest of three numbers A, B, and C.

#include <stdio.h>

int main()
{
    int a,b,c;
    printf("enter the value of a\n");
    scanf("%d",&a);
    printf("enter the value of b\n");
    scanf("%d",&b);
    printf("enter the value of c\n");
    scanf("%d",&c);
    if (a>=b && a>=c)
    {
        printf("%d is largest number",a);
    }
    else if(b>=a && b>=c)
    {
        printf("%d is largest number",b);   
    }
    else if(c>=a && c>=b)
    {
        printf("%d is largest number",c);   
    }
    return 0;
}