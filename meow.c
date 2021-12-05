#include <stdio.h>

void meow(void);

int main()
{
    meow();
}

void meow(void)
{
    for(int i=1; i<=3; i++)
    {
        printf("meow\n");
    }
}