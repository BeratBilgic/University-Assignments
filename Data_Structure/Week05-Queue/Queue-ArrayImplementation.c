#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct 
{
    int cnt;
    int front,rear;
    int data[QUEUE_SIZE];
}queue;

void initialize(queue *q);
int isFull(queue *q);
int isEmpty(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
void displayQueue(queue *q);

int main(){
    int key,loop=1,num;
    queue *q = (queue*)malloc(sizeof(queue));
    
    while (loop)
    {
        printf("\n1 - initialize\n2 - enqueue \n3 - dequeue\n");
        printf("4 - displayQueue\n5 - isFull\n6 - isEmpty\n0 - Exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            initialize(q);
            break;
        case 2:
            printf("\nNumber :");
            scanf("%d", &num);
            enqueue(q, num);
            break;
        case 3:
            num = dequeue(q);
            printf("\nElement at front: %d\n", num);
            break;
        case 4:
            displayQueue(q);
            break;
        case 5:
            printf("\n%d\n", isFull(q));
            break;
        case 6:
            printf("\n%d\n", isEmpty(q));
            break;
        case 0:
            loop = 0;
            break;
        }
    }
    return 0;
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

void displayQueue(queue *q){
    if (isEmpty(q))
        printf("\nQueue is empty\n");
    else
    {
        printf("\n--Queue--\n");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}