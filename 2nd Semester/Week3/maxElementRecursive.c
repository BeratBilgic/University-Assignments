#include <stdio.h>

int findMax(int arr[], int len);

int main(){
    int arr[10] = {1,6,2,9,3,4,9,10,0,8};
    printf("%d\n",findMax(arr, sizeof(arr)/sizeof(arr[0])-1));

    return 0;
}

int findMax(int arr[], int len){
    int x;
    if (len == 0)
    {
        return arr[0];
    }else{
        x = findMax(arr, len-1);
        if (x < arr[len])
        {
            return arr[len];
        }else
        {
            return x;
        }
    }
}
