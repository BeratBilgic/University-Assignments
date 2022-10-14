#include <stdio.h>

int main(){
    int arr[5] = {1,2,3,4,5}, sum = 0, *arrp;
    arrp = arr;
    for (int i = 0; i < 5; i++)
    {
        sum += *(arrp+i);
    }
    printf("%d ",sum);
}