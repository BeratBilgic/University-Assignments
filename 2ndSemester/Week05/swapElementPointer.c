#include <stdio.h>

int main(){
    int arr[5] = {1,2,3,4,5},sArr[5],*arrp;
    arrp = arr;

    for (int i = 0; i < 5; i++)
    {
        sArr[i] = *(arrp+i);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",sArr[i]);
    }
    
}