#include <stdio.h>

int main()
{
    int j = 0;
    char str[32],newStr[32];
    printf("Enter a string: ");
    gets(str);
    
    for (int i = 0; str[i] != '\0' ; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') )
        {
            newStr[j] = str[i];
            j++;
        }
    }
    printf("Output : ");
    puts(newStr);
    printf("\n");

    return 0;
}