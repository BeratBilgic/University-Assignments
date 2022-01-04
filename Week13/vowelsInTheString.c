// Lab 13 - Write the function that finds how many vowels are in the word sent by the user.

#include <stdio.h>

int main()
{
    int vowels = 0;
    char str[32];
    printf("Enter a string : ");
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i]== 'a' || str[i]== 'A' || str[i]== 'e' || str[i]== 'E' || str[i]== 'i' || str[i]== 'I' ||
            str[i]== 'o' || str[i]== 'O' || str[i]== 'u' || str[i]== 'U' )
        {
            vowels++;
        }
    }
    printf("vowels : %d\n",vowels);
    return 0;
}