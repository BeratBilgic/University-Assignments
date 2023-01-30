#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QUEUE_SIZE 30
#define STACK_SIZE 30

typedef struct 
{
    int cnt;
    int front,rear;
    int data[QUEUE_SIZE];
}queue;

typedef struct 
{
    int data[STACK_SIZE];
    int top;
}stack;

void initialize(queue *q);
int isFull(queue *q);
int isEmpty(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
void reset(stack *stk);
void push(stack *stk, int c);
int pop(stack *stk);
int peek(stack *stk);
int checkPalindrome(char str[]);

int main(){
    int isPalindrome;
    char str[30];

    printf("Please enter the word you want to test: ");
    scanf("%s", str);

    isPalindrome = checkPalindrome(str);

    if (isPalindrome)
        printf("\n%s is a palindrome word.\n", str);
    else
        printf("\n%s is NOT a palindrome word.\n", str);

    return 0;
}

int checkPalindrome(char str[]){
    queue *q = (queue*)malloc(sizeof(queue));
    initialize(q);
    stack *s = (stack*)malloc(sizeof(stack));
    reset(s);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            enqueue(q, tolower(str[i]));
            push(s, tolower(str[i]));
        }
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (dequeue(q) != pop(s))
        {
            return 0;
        }
    }

    return 1;
}

void initialize(queue *q){
    q->cnt = 0;
    q->rear = -1;
    q->front = 0;
}

int isFull(queue *q){
    if (q->cnt == QUEUE_SIZE)
        return 1;
    else
        return 0;
}

int isEmpty(queue *q){
    if (q->cnt == 0)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int x){
    if (isFull(q))
        printf("\nQueue is full\n");
    else
    {
        q->rear++;
        q->cnt++;      
        q->data[q->rear] = x;
    }
}

int dequeue(queue *q){
    if (isEmpty(q)){
        printf("\nQueue is empty\n");
        return -100;
    }else
    {
        int x = q->data[q->front];
        q->front++;
        q->cnt--;
        return x;
    }
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