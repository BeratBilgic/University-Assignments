// 12.Write C code to count and print all numbers from LOW to HIGH by steps of STEP. Test with LOW=0 and HIGH=100 and STEP=5.

#include <stdio.h>

int main()
{
    int LOW,HIGH,STEP,i,count=0;
    printf("enter the value of LOW\n");
    scanf("%d",&LOW);
    printf("enter the value of HIGH\n");
    scanf("%d",&HIGH);
    printf("enter the value of STEP\n");
    scanf("%d",&STEP);
    i = LOW;
    while (i <= HIGH)
    {
        printf("%d \n",i);
        i = i + STEP;
        count++;
    }
    printf("\ncounter is %d \n",count);
    
    return 0;
}
/*
output:
enter the value of LOW
0
enter the value of HIGH
100
enter the value of STEP
5

0 
5 
10 
15 
20 
25 
30 
35 
40 
45 
50 
55 
60 
65 
70 
75 
80 
85 
90 
95
100 

counter is 21
*/