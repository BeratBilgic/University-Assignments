#include <stdio.h>
#include <string.h>

int main(){
    char name[20], surName[20];
    int nameLen, surLen, ctr;

    strcpy(name,"Berat");
    strcpy(surName,"Bilgic");

    nameLen = strlen(name);
    surLen = strlen(surName);

    ctr = strcmp(name, surName);
    if (ctr != 0)
    {
        name[nameLen] = ' ';
        strcat(name, surName);
        puts(name);
    }
    
}