#include <stdio.h>
#include <string.h>

int toSort(char arr[], int n1);

int main()
{
    int len;
    char str[32],output[32];
    printf("Enter a string :");
    gets(str);
    len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        output[i] = toSort(str,len);
    }
    puts(output);
    
    return 0;
}

int toSort(char arr[], int n1)
{
    int a = 'z';
    for (int i = 0; i < n1; i++)
    {
        if (arr[i] < a)
        {
            a = arr[i];
        }
    }
    for (int i = 0; i < n1; i++)
    {
        if (arr[i] == a)
        {
            arr[i] = 'z';
            break;
        }
    }

    return a;   
}