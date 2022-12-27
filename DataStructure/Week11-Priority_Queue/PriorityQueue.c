#include <stdio.h>
#include <stdlib.h>

int pq[100];
int size = 0;

void swap(int a, int b) {
    int temp = pq[a];
    pq[a] = pq[b];
    pq[b] = temp;
}

int parent(int i){
    return i / 2;
}

int leftChild(int i){
    return 2 * i;
}
 
int rightChild(int i){
    return (2 * i) + 1;
}

void insert(int x){
    int last = ++size;
    pq[last] = x;

    while (last > 1 && pq[last] > pq[parent(last)])
    {
        swap(last, parent(last));
        last = last/2;
    }
}

int deleteMax(){
    int i = 1;
    int max = pq[i];
    pq[i] = pq[size];

    while (pq[i] < pq[rightChild(i)] || pq[i] < pq[leftChild(i)])
    {
        if (pq[rightChild(i)] > pq[leftChild(i)])
        {
            swap(i, rightChild(i));
            i = rightChild(i);
        }else
        {
            swap(i, leftChild(i));
            i = leftChild(i);
        }
    }

    pq[size] = 0;
    size--;
    return max;
}

void display(){
    printf("\n");
    for (int i = 0; i <= size; i++)
    {
        printf("%-5d " ,i);
    }
    printf("\n");
    for (int i = 0; i <= size; i++)
    {
        printf("%-5d " ,pq[i]);
    }  
    printf("\n");
}

void insertExamples(){
    /*         45
            /      \
           31      14
          /  \    /  \
         13  20  7   11
        /  \
       12   7

    Queue will be represented in the form of array as:
    45 31 14 13 20 7 11 12 7 
    */
   
    size = 0;

    insert(45);
    insert(6);
    insert(34);
    insert(2);
    insert(5);
    insert(34);

/*
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7); */
}

int main(){  
    int key,loop=1,num;
    
    while (loop)
    {
        printf("\n-1 - insertExamples\n1 - insert\n2 - display\n3 - deleteMax\n0 - Exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case -1:
            insertExamples();
            break;
        case 1:
            printf("\nNumber :");
            scanf("%d", &num);
            insert(num);
            break;
        case 2: 
            display();
            break;   
        case 3:
            printf("\nmax = %d\n", deleteMax());
            break;    
        case 0:
            loop = 0;
            break;
        }
    }
    return 0;
}