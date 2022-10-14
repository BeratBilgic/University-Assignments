#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *ptr,i=0;
    ptr = (int*)malloc(1*sizeof(int));
    while(n != 0){
        printf("enter the number\n");
        scanf("%d",&n);
        if (n == 0)
        {
            break;
        }
        ptr = (int*)realloc(ptr,i+1);
        *(ptr+i) = n;
        i++;
    }
    
    for (int j = 0; j < i; j++)
    {
        printf("%d ",*(ptr+j));
    }
    
}