#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
    int data;
    struct nodes *next;
}node;

node* addFront(node *head, int num);
node* addEnd(node *head, int num);
void printList(node *head);
void printListReverse(node *head, node *temp);
int countList(node *head, node *temp);
node *delete(node *head, int num);
node *destroy(node *head);
node* getLast(node *head);

int main(){
    node *head = NULL;
    int key,loop=1,num,count;
    
    while (loop)
    {
        printf("\n1 - Add an element to the beginning of the list\n2 - Add an element to the end of the list\n3 - Print the elements\n");
        printf("4 - Print the elements in reverse\n5 - Count the elements\n6 - Delete an element\n7 - Destroy list\n0 - Exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            printf("Number :");
            scanf("%d",&num);
            head = addFront(head, num);
            break;
        case 2:
            printf("Number :");
            scanf("%d",&num);
            head = addEnd(head, num);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            printListReverse(head, head);
            break;
        case 5:
            count = countList(head,head);
            printf("\nNumber of elements in the list = %d\n",count);
            break;
        case 6:
            printf("The number you want to delete :");
            scanf("%d",&num);
            head = delete(head, num);
            break;
        case 7:
            head = destroy(head);
            break;
        case 0:
            loop = 0;
            break;
        }
    }
    return 0;
}

node* addFront(node *head, int num){
    node *temp = (node*)malloc(sizeof(node)), *last;
    temp->data = num;

    if (head == NULL)
    {
        temp->next = temp;
    }else
    {
        last = getLast(head);
        temp->next = head;
        last->next = temp;
    }

    return temp;
}

node* addEnd(node *head, int num){
    node *temp = (node*)malloc(sizeof(node)), *last;
    temp->data = num;
    
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }else
    {
        last = getLast(head);
        last->next = temp;
        temp->next = head;
    }

    return head;
}

void printList(node *head){
    node *temp = head;
    printf("\nCircular Linked List\n-----------------\n");

    if (head != NULL)
    {
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while (temp != head);
    }
    printf("\n");
}

void printListReverse(node *head, node *temp){
    if (temp->next == head && head != NULL)
    {
        printf("\nReverse nCircular Linked List\n-----------------\n");
        printf("%d ", temp->data);
        return;
    }
    
    printListReverse(head, temp->next);
    printf("%d ", temp->data);
}

int countList(node *head, node *temp){
    if (temp->next == head)
    {
        return 1;
    }
    return countList(head,temp->next) + 1;
}

node *delete(node *head, int num){
    if (head == NULL || !num)
        return head;

    node *temp = head, *ex, *last;
    last = getLast(head);
    
    if (head->data == num)
    {   
        if (temp->next != head)
        {
            head = head->next;
            last->next = head;
        }   
        head = NULL;
        free(temp);
    }else if (last->data == num)
    {
        temp = last;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        temp->next = head;
        free(last);
    }else{
        while (temp != NULL)
        {
            if (temp->data == num)
            {
                ex->next = temp->next;
                free(temp);
                break;
            }
            ex = temp;
            temp = temp->next;
        }
    }
    return head;
}

node *destroy(node *head){
    node *temp = head, *deleted;

    while (temp != head)
    {
        deleted = temp;
        temp = temp->next;
        free(deleted);
    }

    return NULL;
}

node* getLast(node *head){
    node *temp = head;

    if (head == NULL)
    {
        return NULL;
    }
    
    while (temp->next != head)
    {
        temp = temp->next;
    }
    return temp;
}
