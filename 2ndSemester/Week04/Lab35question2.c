#include <stdio.h>

int countOdd(int arr[],int len);

int main(){
    int arr[10] = {1,3,5,7,9,11,2,4,6,8};
    printf("%d\n",countOdd(arr, sizeof(arr)/sizeof(arr[0])-1));

    return 0;
}

int countOdd(int arr[],int len){
if(len == 0){
    if (arr[len] % 2 == 1){
        return 1;
    }else
        return 0;
}else{
    if (arr[len] % 2 == 1)
    {
        return 1 + countOdd(arr,len -1);
    }else{
        return countOdd(arr,len -1);
    }
}
}