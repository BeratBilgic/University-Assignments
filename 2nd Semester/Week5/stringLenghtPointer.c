#include <stdio.h>
#include <stdlib.h>

int main(){
    char str[] = {"Ahmet"},*strp;
    int count = 0;
    strp = str;

    while (*strp != '\0')
    {
        strp++;
        count++;
    }
    printf("%d ",++count);

    return 0;
}