#include <stdio.h>
#include <stdlib.h>

struct node{
    int age;
    struct node *next;                         
};

typedef struct node node;

node* createList();
void traverseList(node* head);
node* deleteGivenAge(node* head,int delAge);

int main(){
    int delAge;
    node *head,p;
    head = createList();
    traverseList(head);
    printf("Age you want to delete = ");
    scanf("%d",&delAge);
    head = deleteGivenAge(head,delAge);
    traverseList(head);
    
    return 0;
}

node* deleteGivenAge(node* head,int delAge){
    node *p, *ex;
    p = head;
    while (p != NULL)
    {
        if (p->age == delAge && p == head)
        {
            head = head->next;
            free(p);
            break;
        }else if (p->age == delAge)
        {
            ex->next = p->next;
            free(p);
            break;
        }
        ex = p;
        p = p->next;
    }
    return head;
}


node* createList(){
    node *ptr,*head;

    for (int i = 0; i < 5; i++)
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
        ptr->age = i+20;
    }
    ptr->next = NULL;
    return head;
}

void traverseList(node* head){
    node *p;
    p = head;
    printf("\n");
    while (p != NULL)
    {
        printf("%d\t",p->age);
        p = p->next;
    } 
    printf("\n");     
}