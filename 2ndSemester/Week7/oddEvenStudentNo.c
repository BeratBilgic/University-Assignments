#include <stdio.h>
#include <stdlib.h>

int findOdd(int no, int *pi);
int findEven(int no, char *pc);

int main(){
    int no = 2010213045, *ptri;
    char *ptrc;
    ptri = (int*)malloc(1*sizeof(int));
    ptrc = (char*)malloc(1*sizeof(char));
    int i = findOdd(no, ptri);
    int c = findEven(no, ptrc);

    for (int j = 0; j < i; j++)
    {
        printf("int %d\n",*(ptri+j));
    }

    for (int k = 0; k < c; k++)
    {
        printf("char %c\n",*(ptrc+k));
    }
    
    
}

int findOdd(int no, int *pi){
    int digit,i=0;
    while (no>0)
    {
        digit = no % 10;

        if (digit % 2 == 1)
        {
            pi = (int*)realloc(pi, i+1);
            *(pi+i) = digit;
            i++;
        }
        
        no = no / 10;
    }
    return i;
}

int findEven(int no, char *pc){
    int digit,c=0;
    while (no>0)
    {
        digit = no % 10;

        if (digit % 2 == 0)
        {
            pc = (char*)realloc(pc, c+1);
            char charDig = digit + '0';
            *(pc+c) = charDig;
            c++;
        }
        
        no = no / 10;
    }
    return c;
}