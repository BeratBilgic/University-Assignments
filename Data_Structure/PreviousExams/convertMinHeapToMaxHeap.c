// Write a function that converts a given min heap which is implemented
// by arrays to a max heap. The prototype of the function is queue *convert(queue *q)

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 50

typedef struct PriorityQueue // Min Heap
{
    int arr[QUEUE_SIZE + 1];
    int cnt;
}queue;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(queue *pq)
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

queue* createTest(){
    /*
              MIN HEAP
                 3
              /     \
            5        9
          /   \     /  \
        6      8  20    10
      /  \    /
    12   18  9 
    */
    int minHeap[] = {0, 3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int size = sizeof(minHeap) / sizeof(minHeap[0]);

    queue* q = (queue*)malloc(sizeof(queue));
    for (int i = 0; i < size; i++){
      q->arr[i] = minHeap[i];
    }
    
    q->cnt = size -1;

    return q;
}

void MaxHeapify(queue *q, int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;
 
    if (l <= q->cnt && q->arr[l] > q->arr[i])
      largest = l;
    if (r <= q->cnt && q->arr[r] > q->arr[largest])
      largest = r;
    if (largest != i) {
      swap(&q->arr[i], &q->arr[largest]);
      MaxHeapify(q, largest);
    }
}

void convertMaxHeap(queue *q){
  for (int i = q->cnt/2; i > 0; i--)
    MaxHeapify(q, i);
} 

int main(){
  queue *q = createTest();
  printf("\nMIN HEAP");
  display(q);
  
  convertMaxHeap(q);
  printf("\nMAX HEAP");
  display(q);
}