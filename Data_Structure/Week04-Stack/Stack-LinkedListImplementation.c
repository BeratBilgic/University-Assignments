#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct 
{
    int cnt;
    struct node *top;
}stack;

#define STACK_SIZE 10

void initalize(stack *stk);
void push(stack *stk, int c);
int pop(stack *stk);
int peek(stack *stk);

int main(){
    int key,loop=1,num;
    stack *stk = (stack*)malloc(sizeof(stack));
    
    while (loop)
    {
        printf("\n1 - initalize\n2 - push\n3 - pop\n");
        printf("4 - peek\n0 - Exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            initalize(stk);
            break;
        case 2:
            printf("Number :");
            scanf("%d", &num);
            push(stk, num);
            break;
        case 3:
            num = pop(stk);
            printf("(pop)Element at top of the stack :%d\n", num);
            break;
        case 4:
            num = peek(stk);
            printf("(peek)Element at top of the stack :%d\n", num);
            break;
        case 0:
            loop = 0;
            break;
        }
    }
    return 0;
}

void initalize(stack *stk){
    stk->cnt = 0;
    stk->top = NULL;
}

void push(stack *stk, int c){
    if (stk->cnt == STACK_SIZE)
        printf("Stack is full\n");
    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
}

int pop(stack *stk){
    if (stk->cnt == 0){
        printf("Stack is empty\n");
        return -1;
    }else{
        int x = stk->top->data;
        struct node *temp = stk->top;
        stk->top = stk->top->next;
        free(temp);
        stk->cnt--;
        
        return x;
    }
}

int peek(stack *stk){
    if (stk->cnt == 0){
        printf("Stack is empty\n");
        return -1;
    }else{
        int x = stk->top->data;
        return x;
    }
}
