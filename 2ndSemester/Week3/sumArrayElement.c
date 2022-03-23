#include <stdio.h>

int sum(int arr[], int len);

int main(){
    int arr[10] = {2,3,6,4,15};
    printf("%d\n",sum(arr, sizeof(arr)/sizeof(arr[0])-1));

    return 0;
}

int sum(int arr[], int len){
    int x;
    if (len == 0)
    {
        return arr[0];
    }else{
        return arr[len] + sum(arr, len-1);
    }
}
