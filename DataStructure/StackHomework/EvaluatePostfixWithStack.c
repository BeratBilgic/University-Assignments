#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
int evaluatePostfix(char exp[]);

int main(){
    char exp[20];
    printf("Enter Postfix Expression\n");
    scanf("%s", exp);
    printf("\nResult: %d\n", evaluatePostfix(exp));

    return 0;
}

int evaluatePostfix(char exp[]){
    int loop=1, num1, num2;
    stack *stk = (stack*)malloc(sizeof(stack));
    reset(stk);

    if (!stk) return -1;

    printf("\n%-10s%-15s%s\n","Input","Action","Details");

    for (int i = 0; exp[i] != '\0'; i++)
    {
        printf("%-10c",exp[i]);

        if (isdigit(exp[i]))
        {
            push(stk ,exp[i]  - '0');
            printf("%-15s\n", "push value");
        }else
        {
            num1 = pop(stk);
            num2 = pop(stk);

            switch (exp[i])
            {
            case '+':
                push(stk, num2 + num1);
                printf("%-15s", "add");
                break;
            case '-':
                push(stk, num2 - num1);
                printf("%-15s", "subtract");
                break;
            case '*':
                push(stk, num2 * num1);
                printf("%-15s", "multiply");
                break;
            case 'x':
                push(stk, num2 * num1);
                printf("%-15s", "multiply");
                break;
            case '/':
                push(stk, num2 / num1);
                printf("%-15s", "divide");
                break;
            }
            printf("pop %d pop %d push %d%c%d = %d\n",num1, num2, num2, exp[i], num1, peek(stk));
        }
    }

    return pop(stk);
}

void reset(stack *stk){
    stk->top = -1;
}

void push(stack *stk, int c){
    if(stk->top == STACK_SIZE-1)
        printf("Stack is full");
    else
    {
        stk->data[++stk->top] = c;
    }
}

int pop(stack *stk){
    if(stk->top == -1){
        printf("Stack is empty\n");
        return -1;
    }else{
        return stk->data[stk->top--];
    }
}

int peek(stack *stk){
    if(stk->top == -1){
        printf("Stack is empty\n");
        return -1;
    }else{
        return stk->data[stk->top];
    }
}