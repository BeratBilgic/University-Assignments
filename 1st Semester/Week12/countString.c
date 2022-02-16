// Lab 12 - Write C Program to Count the Number of Vowels, Consonants and so on

#include <stdio.h>

int main ()
{
    int spaces = 0,digit = 0,consonants = 0,vowels = 0;
    char str[32];
    printf("Enter a string : ");
    gets(str);

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' '){
            spaces++;
        }
        else if (str[i] >= '0' && str[i] <= '9'){
            digit++;
        }
        else if (str[i]== 'a' || str[i]== 'A' || str[i]== 'e' || str[i]== 'E' || str[i]== 'i' || str[i]== 'I' ||
                str[i]== 'o' || str[i]== 'O' || str[i]== 'u' || str[i]== 'U' ){
            vowels++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            consonants++;
        }
    }
    printf("Vowels = %d\n",vowels);
    printf("Consonants = %d\n",consonants);
    printf("Digit = %d\n",digit);
    printf("White spaces = %d\n",spaces);

    return 0;
}