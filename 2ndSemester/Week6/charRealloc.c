#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[] = "Berat", surname[] = "Bilgic";
    char *ptr;
    int i,j;
    ptr = (char*)malloc(5 * sizeof(char));
    for (i = 0; i < 5; i++)
    {
        strcpy((ptr+i),&name[i]);
    }
    
    printf("%s",(ptr));  
    printf("\n");

    ptr = (char*)realloc(ptr, 12);
    *(ptr+i) = ' ';
    i++;
    
    for ( j = 0; j < 6; i++, j++)
    {
        strcpy((ptr+i),&surname[j]);
    }
    
    printf("%s",(ptr));  

    return 0;
}