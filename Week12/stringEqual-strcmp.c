#include <stdio.h>

int main ()
{
    char str1[32],str2[32];
    printf("enter first string\n");
    gets(str1);
    printf("enter second string\n");
    gets(str2);
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if ( str1[i] != str2[i])
        {
            printf("strings are not same\n");
            return 0;
        }
    }
    printf("strings are same\n");
    return 0;
}