#include <stdio.h>

int main()
{
    char str[40],temp;
    int k = 0;
    printf("write something \n");
    gets(str);
    while (str[k]!='\0')
    {
        k++;
    }
    temp = str[k-1];
    str[k-1] = str[0];
    str[0] = temp;
    puts(str);

    return 0;
}