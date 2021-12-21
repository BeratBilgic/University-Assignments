#include <stdio.h>

int main()
{
    char str[32];
    int i = 0;
    printf("enter string \n");
    gets(str);
    while (str[i] != '\0')
    {
        str[i] = str[i] + 1;
        if (str[i] == 123 || str[i] == 91 )
        {
            str[i] = str[i] - 26;
        }
        i++;  
    }
    puts(str);
    
    return 0;
}