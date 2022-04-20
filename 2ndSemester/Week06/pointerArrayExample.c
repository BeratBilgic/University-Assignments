#include <stdio.h>
#include <stdlib.h>

int *combineArr(int len1, int arr1[], int len2, int arr2[]);
int *orderArr(int *arr, int len);

int main(){
    int arr1[6] = {1,5,11,13,14,21}, arr2[7] = {2,3,12,13,15,17,25};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    int *comPtr;
    comPtr = combineArr(len1, arr1, len2, arr2);
    comPtr = orderArr(comPtr, len1 + len2);

    for (int i = 0; i < len1+len2; i++)
    {
        printf("%d ", *(comPtr + i));
    }
    
}

int *combineArr(int len1, int arr1[], int len2, int arr2[]){
    int *result = (int*)calloc(len1 + len2, sizeof(int));
    int i,k;

    for ( i = 0; i < len1; i++)
    {
        *(result+i) = arr1[i];
    }

    for ( k = 0; k < len2; k++, i++)
    {
        *(result+i) = arr2[k];
    }

    return result;
}

int *orderArr(int *arr, int len){
    int temp;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (*(arr + j) > *(arr + i))
            {  
                temp = *(arr+i);
                *(arr+i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
        
    }

    return arr;
}