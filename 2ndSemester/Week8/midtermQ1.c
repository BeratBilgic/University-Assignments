#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill(int len, char *ptr, char name[]);
int findSum(int no);

int main(){
    char name[] = "Berat",*ptr;
    int no = 2010213045,lenNa, sumNo;
    lenNa = strlen(name);
    ptr = (char*)malloc(lenNa * sizeof(char));
    fill(lenNa,ptr,name);
    puts(ptr);

    sumNo = findSum(no);
    ptr = (char*)realloc(ptr, sumNo);
    fill(sumNo,ptr,name);
    puts(ptr);
}

void fill(int len, char *ptr, char name[]){
    int lenStr = strlen(name);
    int i;
    len = len - (len % lenStr);
    for ( i = 0; i < len; i++)
    {
        *(ptr + i) = name[i%lenStr];
    }
    *(ptr + i) = '\0';
}

int findSum(int no){
    int sum = 0,digit;
    while (no > 0)
    {
        digit = no % 10;
        sum += digit;
        no/=10;
    }
    return sum;
}
