#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct 
{
    int data[STACK_SIZE];
    int top;
}stack;

void reset(stack *stk);
void push(stack *stk, int c);
int pop(stack *stk);
int peek(stack *stk);

int main(){
    int key,loop=1,num;
    stack *stk = (stack*)malloc(sizeof(stack));
    
    while (loop)
    {
        printf("\n1 - reset\n2 - push\n3 - pop\n");
        printf("4 - peek\n0 - Exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            reset(stk);
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

void reset(stack *stk){
    stk->top = -1;
}

void push(stack *stk, int c){
    if(stk->top == STACK_SIZE-1)
        printf("Stack is full");
    else
    {
        stk->top++;
        stk->data[stk->top] = c;
        //stk->data[++stk->top] = c;
    }
}

int pop(stack *stk){
    if(stk->top == -1){
        printf("Stack is empty\n");
        return -1;
    }else{
        int x = stk->data[stk->top];
        stk->top--;
        return x;
        //return stk->data[stk->top--];
    }
}

int peek(stack *stk){
    if(stk->top == -1){
        printf("Stack is empty\n");
        return -1;
    }else{
        int x = stk->data[stk->top];
        return x;
        //return stk->data[stk->top];
    }
}