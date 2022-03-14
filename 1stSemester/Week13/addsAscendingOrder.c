// Lab 13 - Write a function that adds a given element to an array in ascending order without changing the order of the array.

#include <stdio.h>

void toSort(int arr1[],int n1);

void printArr(int ary2[], int n2);

void toAdd(int arr2[], int n2, int add);

int main()
{
    int n,add,a,b,i;
    printf("enter the number of terms\n");
    scanf("%d",&n);
    int input[n],ord[n+1],output[n+1];
    for (int i = 0; i < n; i++){
        printf("Array[%d] = ",i);
        scanf("%d",&input[i]);
    }

    toSort(input,n);
    printArr(input,n);

    printf("Number to add = ");
    scanf("%d",&add);

    toAdd(input,n+1,add);
    printArr(input,n+1);
    
    return 0;
}

void toSort(int arr1[],int n1){
    int temp;
    for (int i = 0; i < n1 ; i++){
        for (int j = 0; j < n1; j++){
            if (arr1[i] < arr1[j]){
                temp =  arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }
}
void toAdd(int arr2[], int n2, int add){
    int a,i,j,b;
    for (i = 0; i < n2; i++){
        if (add < arr2[i]){
            a = arr2[i];
            for (int j = i; j < n2; j++){
                b = arr2[j+1];
                arr2[j+1] = a;
                a = b; 
            }
            arr2[i] = add;
            break;
        }
        else if (i == n2-1){
            arr2[i] = add;
        }
    }
}
void printArr(int arr2[], int n2){
    for (int i = 0; i < n2; i++){
        printf("%d ",arr2[i]);
    }
    printf("\n");
}