#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int binary[40], no = 2010213045, digit,i = 0,len,*ptr;
    while (no > 0)
    {
        digit = no%2;
        binary[i] = digit;
        no/=2;
        i++;
    }
    ptr = (int*)malloc(1*sizeof(int));

    len = i;

    for (int j = 0; j < len; j++)
    {
        ptr = (int*)realloc(ptr,j+1);
        i--;
        *(ptr + j) =  binary[i];
        printf("%d",*(ptr + j));
    }

    return 0;
}