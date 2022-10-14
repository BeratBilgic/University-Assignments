#include <stdio.h>

void swap(int *p1,int *p2);

int main(){
    int a=5,b=4,*ptr1,*ptr2;
    ptr1 = &a;
    ptr2 = &b;
    printf("ptr1 = %d ptr2 = %d\n",*ptr1,*ptr2);
    swap(ptr1,ptr2);
    printf("ptr1 = %d ptr2 = %d\n",*ptr1,*ptr2);
}

void swap(int *p1,int *p2){
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}