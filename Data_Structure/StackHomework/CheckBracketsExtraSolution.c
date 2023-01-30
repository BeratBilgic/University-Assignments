#include <stdio.h>
#include<stdlib.h>
#define STACK_SIZE 20

typedef struct {
    char data[STACK_SIZE];
    int top;
}stack;


void initialize(stack *stk){
    stk->top = -1;
}

void push(stack *stk, char c){
    if(stk->top != STACK_SIZE-1){
        stk->top++;
        stk->data[stk->top]=c;
    }
    else{
        printf("This stack is full.\n");
    }
}

int pop(stack *stk){
    if(stk->top != -1){
        return stk->data[stk->top--];
    }
    printf("\n stack is empty !");
    return -1;
}


int main(){
    char key;
    stack stk;
    initialize(&stk);
    FILE *fptr;
    if((fptr=fopen("code.txt","r"))==NULL){
        printf("There is no file.\n");
        return 0;
    }else{
        while(!feof(fptr)){
            key=getc(fptr);
            switch (key)
            {
            case '(':
                push(&stk,key);
                break;

            case ')':
                if(pop(&stk)=='(')
                continue; 
                
                else{
                    printf("\n Error for ( or ) \n");
                    exit(1);
                }
                break;
            case '{':
                push(&stk,key);
                break;

            case '}':
                if(pop(&stk)=='{')
                    continue; 
                else{
                        printf("\n Error for { or } \n");
                        exit(1);
                    }
                break;

            case'[':
                push(&stk,key);
                break;

            case']':
                if(pop(&stk) == '[')
                    continue;

                else{
                    printf("\n Error for [ or ] \n");
                    exit(1);
                }
                break;
            }
        }
        if(stk.top == -1){
            printf("No error in our code.");

        }
        else{
            printf("Error, there is at least one opening paranthesis which is not closed!");

        }
        fclose(fptr);
        return 0;
    }
}