#include <stdio.h>
#include <stdlib.h>

struct node{
    int number;
    struct node *next;                          
};

typedef struct node node;

node* createList();
int traverseList(node* head);
node* deleteMiddleElement(node* head,int len);

int main(){
    int counter;
    node *head;
    head = createList();
    counter = traverseList(head);
    head = deleteMiddleElement(head,counter);
    counter = traverseList(head);
    
    return 0;
}

node* deleteMiddleElement(node* head,int len){
    node *p,*ex;
    p = head;
    int counter = 1,midNo;
    midNo = len/2;
    if (midNo <= 1)
    {
        head = p->next;
        free(p);
    }else
    {
        while (counter != midNo)
        {
            ex = p;
            p = p->next;
            counter++;
        }
        ex->next = p->next;
        free(p);
    }

    return head;
}


node* createList(){
    node *ptr,*head;

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            head = (node*)malloc(sizeof(node));
            ptr = head;
        }else
        {
            ptr->next = (node*)malloc(sizeof(node));
            ptr = ptr->next;
        }
        ptr->number = i+1;
    }
    ptr->next = NULL;
    return head;
}

int traverseList(node* head){
    int counter = 0;
    node *p;
    p = head;
    printf("\n");
    while (p != NULL)
    {
        printf("%d\t",p->number);
        p = p->next;
        counter++;
    } 
    printf("\n");     

    return counter;
}