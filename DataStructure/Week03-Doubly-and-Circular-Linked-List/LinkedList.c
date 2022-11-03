#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
    int data;
    struct nodes *next;
}node;

node *addFront(node *head, int num);
node *addEnd(node *head, int num);
void printList(node *head);
void printListReverse(node *head);
int countList(node *head);
node *delete(node *head, int num);
node *destroy(node *head);

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
            printListReverse(head);
            break;
        case 5:
            count = countList(head);
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

node *addFront(node *head, int num){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->next = head;

    return temp;
}

node *addEnd(node *head, int num){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    
    if (head == NULL)
    {
        head = temp;
    }else
    {
        node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
    }

    return head;
}

void printList(node *head){
    printf("\nLinked List\n-----------------\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }   
    printf("\n");
}

void printListReverse(node *head){
    if (head == NULL)
    {
        printf("\nReverse Linked List\n-----------------\n");
        return;
    }
    
    printListReverse(head->next);
    printf("%d ", head->data);
}

int countList(node *head){
    if (head->next == NULL)
    {
        return 1;
    }
    return countList(head->next) + 1;
}

node *delete(node *head, int num){
    if (head == NULL || !num)
        return head;

    node *temp = head, *prev;
    
    if (head->data == num)
    {
        head = head->next;
        free(temp);
        return head;
    }
    
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

node *destroy(node *head){
    node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return NULL;
}
