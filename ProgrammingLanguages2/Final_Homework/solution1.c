#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int no;
    struct student *next;
};
typedef struct student student;

void traverseList(student* head);
student* createList();
student* reverseList(student* head);

int main(){
    int key,loop=1;
    student *head;
    
    while (loop)
    {
        printf("\n1-createList()\n2-traverseList(head)\n3-reverseList(head)\n0-exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            head = createList();
            break;
        case 2:
            traverseList(head);
            break;
        case 3:
            head = reverseList(head);
            break;
        default:
            loop = 0;
            break;
        }
    }
    
    return 0;
}

void traverseList(student* head){
    student *p;
    p = head;
    printf("\n");
    while (p != NULL)
    {
        printf("%d\n",p->no);
        p = p->next;
    }       
}

student* createList(){
    student *ptr,*head;

    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            head = (student*)malloc(sizeof(student));
            ptr = head;
        }else
        {
            ptr->next = (student*)malloc(sizeof(student));
            ptr = ptr->next;
        }
        ptr->no = i+1;
    }
    ptr->next = NULL;
    return head;
}

student* reverseList(student* head){
    student *ptr,*next,*ex;
    ptr = head;
    ex = NULL;
    while (ptr != NULL)
    {
        next = ptr->next;
        ptr->next = ex;
        ex = ptr;
        ptr = next;
    }
    
    return ex;
}