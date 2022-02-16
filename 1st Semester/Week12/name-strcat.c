// Lab 12 - Write C Program to Concatenate Two Strings.

#include <stdio.h>

int main()
{
    char name[32],surName[32],fullName[64];
    int i = 0 , j = 0 ;
    printf("enter a your name\n");
    gets(name);
    printf("enter a your surname\n");
    gets(surName);

    while (name[i] != '\0'){
        fullName[i] = name[i];
        i++;
    }
    fullName[i] = ' ';
    i++;
    while (surName[j] != '\0'){
        fullName[i] = surName[j];
        i++;
        j++;
    }
    puts(fullName);

    return 0;
}