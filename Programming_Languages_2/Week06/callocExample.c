#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,*ptr,max = 0;
    printf("Enter the number of terms\n");
    scanf("%d",&n);
    ptr = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter value\n");
        scanf("%d",&*(ptr+i));
    }

    for (int i = 0; i < n; i++)
    {
        if (max < *(ptr+i))
        {
            max = *(ptr+i);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
    
    printf("\nGreatest value = %d\n",max);

    return 0;
}