// Write a function if a given double linked list of 
// characters (each node has just one character as data) is palindrome or not? 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct nodes
{
    char data;
    struct nodes *prev;
    struct nodes *next;
}node;

node* addEnd(node *head, char c){
    node *temp = (node*)malloc(sizeof(node)), *last;
    temp->data = c;
    temp->next = NULL;
    
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }else
    {
        last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = temp;
        temp->prev = last;
    }

    return head;
}

node* loadStringToLinkedList(node *head, char str[]){
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            head = addEnd(head, tolower(str[i]));            
        }
    }

    return head;
}

int isPalindrome(node *head){
    if (head == NULL)
       return 1;
 
    node *last = head;
    while (last->next != NULL)
        last = last->next;
 
    while (head != last){
        if (head->data != last->data)
            return 0;
 
        head = head->next;
        last = last->prev;
    }
 
    return 1;
}

int main(){
    char str[32];
    node *head = NULL;

    printf("Please enter the word you want to test: ");
    scanf("%s", str);   

    head = loadStringToLinkedList(head, str);

    if (isPalindrome(head))
        printf("\n%s is a palindrome word.\n", str);
    else
        printf("\n%s is NOT a palindrome word.\n", str);

    return 0;
}