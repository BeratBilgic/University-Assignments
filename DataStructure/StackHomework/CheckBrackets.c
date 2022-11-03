#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct 
{
    char data[STACK_SIZE];
    int top;
}stack;

void reset(stack *stk);
void push(stack *stk, int c);
int pop(stack *stk);
int peek(stack *stk);
int checkBrackets(FILE *fptr);
int isMatchingBrackets(char char1, char char2);
void printAllStack(stack *stk);

int main(){
    FILE *fptr;
    if ((fptr = fopen("code.txt","r")) == NULL)
    {
        printf("File could not be opened\n");
    }else
    {
        int isBalanced = checkBrackets(fptr);
        if (isBalanced)
        {
            printf("\nParentheses/braces are nested properly\n");
        }else
        {
            printf("\nParentheses/brances are NOT nested properly\n");
        }
    }
    
    return 0;
}

int checkBrackets(FILE *fptr){
    char ch, topData;
    stack *stk = (stack*)malloc(sizeof(stack));
    reset(stk);

    printf("\n%-10s%-10s%s\n","Input","Action","Stack");

    while (!feof(fptr))
    {
        ch = fgetc(fptr);
        if (ch == '(' || ch == '[' || ch == '{')
        {   
            push(stk, ch);
            printf("%-10c%-10s" ,ch ,"push");
            printAllStack(stk);

        }else if (ch == ')' || ch == ']' || ch == '}')
        {
            topData = pop(stk);

            if (!isMatchingBrackets(topData, ch))
            {
                push(stk, topData);
                printf("%-10c%-10s" ,ch ,"error");
                printAllStack(stk);
                return 0;
            }
            
            printf("%-10c%-10s" ,ch ,"pop");
            printAllStack(stk);
        }
    }

    fclose(fptr);

    if (stk->top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}

int isMatchingBrackets(char char1, char char2){
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else
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
        stk->data[++stk->top] = c;
    }
}

int pop(stack *stk){
    if(stk->top == -1){
        //printf("Stack is empty\n");
        return -1;
    }else{
        return stk->data[stk->top--];
    }
}

int peek(stack *stk){
    if(stk->top == -1){
        //printf("Stack is empty\n");
        return -1;
    }else{
        return stk->data[stk->top];
    }
}

void printAllStack(stack *stk){
    for (int i = 0; i <= stk->top; i++)
    {
        printf("%c ", stk->data[i]);
    }
    printf("\n");
}