#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node *next;
};

typedef struct node node;

void traverseList(node *head);
void checkOddEven(node *ehead, node *ohead, int no);

int main(){
    int no;
    node *ehead, *ohead;

    ehead = (node*)malloc(sizeof(node));
    ehead->num = -1;

    ohead = (node*)malloc(sizeof(node));
    ohead->num = -1;

    printf("Student Number : ");
    scanf("%d",&no);
    checkOddEven(ehead, ohead, no);
    printf("Result :\n");
    traverseList(ohead);
    traverseList(ehead);
}

void checkOddEven(node *ehead, node *ohead, int no){
    int digit;
    node *eptr, *optr;
    eptr = ehead;
    optr = ohead;

    while (no>0)
    {
        digit = no % 10;
        no = no / 10;    
        if (digit % 2 == 0)
        {
            if (eptr->num != -1)
            {
                eptr->next = (node*)malloc(sizeof(node));
                eptr = eptr->next;
            }
            eptr->num = digit;
        }else
        {
            if (optr->num != -1)
            {
                optr->next = (node*)malloc(sizeof(node));
                optr = optr->next;
            }
            optr->num = digit;
        }
    }
    eptr->next = NULL;
    optr->next = NULL;
}

void traverseList(node *head){
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ",ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}