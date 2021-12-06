#include <stdio.h>

int main()
{
    int v,f,p,no;
    printf("enter the Student ID\n");
    scanf("%d",&no);
    printf("enter the midterm grade\n");
    scanf("%d",&v);
    printf("enter the midterm grade\n");
    scanf("%d",&f);
    p = f*0.6 + v*0.4;
    printf("your Student ID is %d\n",no);
    printf("your passing grade is %d",p);

    return 0;
}