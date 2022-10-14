#include <stdio.h>

void selectionSort(int arr[], int len);
void printArray(int arr[], int len);

int main(){
    int arr[] = {5,6,2,3,8,1,4,7};
    printArray(arr,8);
    printf("**********\n");
    selectionSort(arr,8);
    printf("**********\n");
    printArray(arr,8);
}

void selectionSort(int arr[], int len){
    int min, iMin;
    for (int i = 0; i < len; i++)
    {
        min = arr[i];
        iMin = i;
        for (int j = i; j < len; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                iMin = j;
            }
        }
        arr[iMin] = arr[i];
        arr[i] = min;
        printArray(arr,len);
    }
}

void printArray(int arr[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
