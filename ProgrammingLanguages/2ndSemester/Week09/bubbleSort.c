#include <stdio.h>

void bubbleSort(int arr[], int len);
void printArray(int arr[], int len);

int main(){
    int arr[] = {5,6,2,3,8,1,4,7};
    printArray(arr,8);
    printf("**********\n");
    bubbleSort(arr,8);
    printf("**********\n");
    printArray(arr,8);
}

void bubbleSort(int arr[], int len){
    int temp;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                printArray(arr,8);
            }
        }
    }
}

void printArray(int arr[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}