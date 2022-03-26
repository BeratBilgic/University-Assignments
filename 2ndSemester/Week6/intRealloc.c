#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,*ptr,max = 0,i;
    printf("Enter the number of terms\n");
    scanf("%d",&n);
    ptr = (int*)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Enter value\n");
        scanf("%d",&*(ptr+i));
    }
    
    for (int k = 0; k < n; k++)
    {
        printf("address = %d\tvalue = %d \n",(ptr+k),*(ptr+k));
    }

    printf("Enter the new number of terms\n");
    scanf("%d",&n);
    ptr = (int*)realloc(ptr, n);

    while (i < n)
    {
        printf("Enter value\n");
        scanf("%d",&*(ptr+i));
        i++;
    }
    for (int k = 0; k < n; k++)
    {
        printf("address = %d\tvalue = %d \n",(ptr+k),*(ptr+k));
    }
    
    return 0;
}