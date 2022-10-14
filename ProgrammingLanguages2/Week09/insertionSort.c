#include <stdio.h>

void insertionSort(int arr[], int len);
void printArray(int arr[], int len);

int main(){
    int arr[] = {5,6,2,3,8,1,4,7};
    printArray(arr,8);
    printf("**********\n");
    insertionSort(arr,8);
    printf("**********\n");
    printArray(arr,8);
}

void insertionSort(int arr[], int len){
    int temp;
    for (int i = 0; i < len; i++)
    {
        temp = arr[i];
        for (int j = i; j >= 0 ; j--)
        {
            if (temp < arr[j])
            {
                arr[j+1] = arr[j];
                arr[j] = temp;
                printArray(arr,len);
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
