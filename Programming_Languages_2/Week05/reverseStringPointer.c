#include <stdio.h>

int main(){
    char str[] = {"ahmet"},revStr[6],*strp,j=0;
    strp = str;

    for (int i = 4; i >= 0; i--)
    {
        revStr[j] = *(strp + i);
        j++; 
    }
    revStr[j] = '\0';
    puts(revStr);
}