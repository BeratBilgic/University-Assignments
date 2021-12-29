#include <stdio.h>

int findSmallest(int arr1[],int n1);

void printArr(int ary2[], int n2);

int main()
{
    int n,add,a,b,i;
    printf("enter the number of terms\n");
    scanf("%d",&n);
    int input[n],ord[n+1],output[n+1];
    for (int i = 0; i < n; i++)
    {
        printf("Array[%d] = ",i);
        scanf("%d",&input[i]);
    }

    for (int i = 0; i < n; i++)
    {
        ord[i] = findSmallest(input,n);
    }

    printArr(ord,n);
    printf("Number to add = ");
    scanf("%d",&add);

    for (i = 0; i < n+1; i++)
    {
        if (add < ord[i])
        {
            a = ord[i];
            for (int j = i; j < n+1; j++)
            {
                b = ord[j+1];
                ord[j+1] = a;
                a = b; 
            }
            ord[i] = add;
            break;
        }
        else if (i == n)
        {
            ord[i] = add;
        }
    }
    printArr(ord,n+1);
    
    return 0;
}

int findSmallest(int arr1[],int n1)
{
    int min = 99999999;
    for (int i = 0; i < n1 ; i++)
    {
        if (arr1[i] < min)
        {
            min = arr1[i]; 
        }   
    }
    for (int i = 0; i < n1 ; i++)
    {
        if (arr1[i] == min)
        {
            arr1[i] = 99999999; 
            break;
        }   
    }
    
    return min;
}

void printArr(int arr2[], int n2)
{
    for (int i = 0; i < n2; i++)
    {
        printf("%d ",arr2[i]);
    }
    printf("\n");
}