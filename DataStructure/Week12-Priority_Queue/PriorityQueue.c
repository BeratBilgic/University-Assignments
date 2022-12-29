#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 50

typedef struct PriorityQueue // Min Heap
{
    int arr[QUEUE_SIZE + 1];
    int cnt;
}PQ;

void initialize(PQ *pq)
{
    pq->cnt = 0;
    pq->arr[0] = 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i)
{
    return i / 2;
}

int leftChild(int i)
{
    return 2 * i;
}

int rightChild(int i)
{
    return (2 * i) + 1;
}

void insert(PQ *pq, int x)
{
    if (pq->cnt == QUEUE_SIZE)
        printf("Queue is full");
    else
    {
        pq->cnt++;
        int iter = pq->cnt;
        pq->arr[iter] = x;

        while (iter > 1 && pq->arr[iter] < pq->arr[parent(iter)])
        {
            int temp = pq->arr[iter];
            pq->arr[iter] = pq->arr[parent(iter)];
            pq->arr[parent(iter)] = temp;

            iter = iter / 2;
        }
    }
}

int deleteMin(PQ *pq)
{
    if (pq->cnt == 0)
    {
        printf("\nQueue is empty\n");
        return -1000;
    }
    else
    {
        int iter = 1;
        int min = pq->arr[iter];
        pq->arr[iter] = pq->arr[pq->cnt];

        while (iter * 2 <= pq->cnt && (pq->arr[iter] > pq->arr[rightChild(iter)] || pq->arr[iter] > pq->arr[leftChild(iter)]))
        {
            if (rightChild(iter) > pq->cnt)
            {
                swap(&pq->arr[iter], &pq->arr[leftChild(iter)]);
                iter = leftChild(iter);
            }
            else if (pq->arr[rightChild(iter)] < pq->arr[leftChild(iter)])
            {
                swap(&pq->arr[iter], &pq->arr[rightChild(iter)]);
                iter = leftChild(iter);
            }
            else
            {
                swap(&pq->arr[iter], &pq->arr[leftChild(iter)]);
                iter = leftChild(iter);
            }
        }

        pq->arr[pq->cnt] = 0;
        pq->cnt--;

        return min;
    }
}

void display(PQ *pq)
{
    if (pq->cnt == 0)
        printf("\nQueue is empty\n");
    else
    {
        printf("\n");
        for (int i = 0; i <= pq->cnt; i++)
        {
            printf("%-5d ", i);
        }
        printf("\n");
        for (int i = 0; i <= pq->cnt; i++)
        {
            printf("%-5d ", pq->arr[i]);
        }
        printf("\n");
    }
}

void insertExamples(PQ *pq)
{
    /*     
                7
            /      \
           8       14
          /  \    /  \
         31  15  19   24
        /  
       45   

    Queue will be represented in the form of array as:
    7 8 14 31 15 19 24 45   

    */

    pq->cnt = 0;

    insert(pq, 45);
    insert(pq, 7);
    insert(pq, 14);
    insert(pq, 8);
    insert(pq, 15);
    insert(pq, 19);
    insert(pq, 24);
    insert(pq, 31);
}

int main() 
{
    int key, loop = 1, num;
    PQ pq;
    initialize(&pq);

    while (loop)
    {
        printf("\nPriority Queue Min Heap\n-1 - insertExamples\n1 - insert\n2 - display\n3 - deleteMin\n0 - Exit\n");
        scanf("%d", &key);
        switch (key)
        {
        case -1:
            insertExamples(&pq);
            break;
        case 1:
            printf("\nNumber :");
            scanf("%d", &num);
            insert(&pq, num);
            break;
        case 2:
            display(&pq);
            break;
        case 3:
            printf("\nmin = %d\n", deleteMin(&pq));
            break;
        case 0:
            loop = 0;
            break;
        }
    }
    return 0;
}