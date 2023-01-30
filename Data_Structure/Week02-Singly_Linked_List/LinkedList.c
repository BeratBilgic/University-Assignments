#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
    int num;
    struct nodes *next;
}node;

node* addFront(node *head, int num);
node* addEnd(node *head, int num);
void printList(node *head);
void printListReverse(node *head);
int countList(node *head);

int main(){
    node *head = NULL;
    int key,loop=1,num,count;
    
    while (loop)
    {
        printf("\n1 - Add an element to the beginning of the list\n2 - Add an element to the end of the list\n3 - Print the elements\n");
        printf("4 - Print the elements in reverse\n5 - Count the elements\n0 - Exit\n");
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
        default:
            loop = 0;
            break;
        }
    }
    return 0;
}

node* addFront(node *head, int num){
    node *temp = (node*)malloc(sizeof(node));
    temp->num = num;
    temp->next = head;

    return temp;
}

node* addEnd(node *head, int num){
    node *temp = (node*)malloc(sizeof(node));
    temp->num = num;
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
        printf("%d\n", head->num);
        head = head->next;
    }   
}

void printListReverse(node *head){
    if (head == NULL)
    {
        printf("\nReverse Linked List\n-----------------\n");
        return;
    }
    
    printListReverse(head->next);
    printf("%d\n", head->num);
}

int countList(node *head){
    if (head->next == NULL)
    {
        return 1;
    }
    return countList(head->next) + 1;
}
