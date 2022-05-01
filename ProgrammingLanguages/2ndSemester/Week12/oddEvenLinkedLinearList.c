#include <stdio.h>
#include <stdlib.h>

struct node{
    int number;
    struct node *next;
};

typedef struct node node;

void traverseList(node* head);
node* addBeginning(node* head, int num);
node* addEnd(node* last, int num);


int main(){
    int num;
    node *head,*new,*last;
    head = (node*)malloc(sizeof(node));
    head->next = (node*)malloc(sizeof(node));
    printf("Enter the number = ");
    scanf("%d",&num);
    if (num != -1)
    {
        head->number = num;
        head->next = NULL;
        last = head;
    }
    while (num != -1)
    {
        printf("Enter the number = ");
        scanf("%d",&num);
        if (num % 2 == 0 && num != -1)
        {
            last = addEnd(last,num);
            
        }else if(num % 2 == 1 && num != -1){
            
            head = addBeginning(head,num);
        }
    }
    traverseList(head);

    return 0;
}

node* addBeginning(node* head, int num){
    node *new;
    new = (node*)malloc(sizeof(node));
    new->next = (node*)malloc(sizeof(node));

    new->number = num;
    new->next = head;

    return new;
}

node* addEnd(node* last, int num){
    node *new;
    new = (node*)malloc(sizeof(node));
    new->next = (node*)malloc(sizeof(node));

    last->next = new;
    new->number = num;
    new->next = NULL;

    return new;
}

void traverseList(node* head){
    node *p;
    p = head;
    printf("\n");
    while (p != NULL)
    {
        printf("%d\t",p->number);
        p = p->next;
    }    
    printf("\n");   
}