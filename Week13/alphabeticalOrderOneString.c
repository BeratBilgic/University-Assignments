// Lab 13 - Write a program that puts the characters in the string sent to the function in alphabetical order.

#include <stdio.h>

void setString(char str[]);

int main(){
    char str1[32];
    printf("Enter a string: ");
    gets(str1);
    setString(str1);
    puts(str1);

    return 0;
}

void setString(char str[]){
    char a; 
    for (int i = 0; str[i] != '\0'; i++){
        for (int j = 0; str[j] != '\0'; j++){
            if (str[i] < str[j] && str[i] != ' '){
                a = str[i];
                str[i] = str[j];
                str[j] = a; 
            }   
        }
    }
}