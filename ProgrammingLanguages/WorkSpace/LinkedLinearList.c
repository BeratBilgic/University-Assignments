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
student* addNode(student* head);
student* deleteNode(student* head);

int main(){
    int key,loop=1;
    student *head;
    
    while (loop)
    {
        printf("\n1-createList()\n2-traverseList(head)\n3-addNode(head)\n4-deleteNode(head)\n");
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
            head = addNode(head);
            break;
        case 4:
            head = deleteNode(head);
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

student* addNode(student* head){
    student *new;
    new = (student*)malloc(sizeof(student));
    new->next = (student*)malloc(sizeof(student));
    printf("No = ");
    scanf("%d",&new->no);
    printf("Name = ");
    scanf("%s",new->name);
    printf("Age = ");
    scanf("%d",&new->age);
    new->next = head;
    head = new;

    return head;
}

student* deleteNode(student* head){
    student *p,*ex;
    int no;
    printf("The number of the student you want to delete = ");
    scanf("%d",&no);

    p = head;

    while (p != NULL)
    {
        if (p->no == no && p == head)
        {
            head = p->next;
            free(p);
            break;
        }else if (p->no == no)
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
