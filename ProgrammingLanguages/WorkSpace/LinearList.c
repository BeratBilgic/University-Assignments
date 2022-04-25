#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int no;
    char name[30];
    int age;
    struct student *next;
};
typedef struct student student;

void traverseList(student* head);

student* createList();

int main(){
    student *head;
    head = createList();
    traverseList(head);
}

void traverseList(student* head){
    student *p;
    p = head;
    while (p != NULL)
    {
        printf("%d\t%s\t%d\n",p->no,p->name,p->age);
        p = p->next;
    }       
}

student* createList(){
    student *ptr,*head;

    for (int i = 0; i < 3; i++)
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
        ptr->age = i+11;
        strcpy(ptr->name,"name");
    }
    ptr->next = NULL;
    return head;
}