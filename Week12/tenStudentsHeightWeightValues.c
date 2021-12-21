#include <stdio.h>

int main()
{
    int s[10][2],sum1 = 0,sum2 = 0,ave1,ave2;
    printf("enter students' height and weight\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d\t%d",&s[i][0],&s[i][1]);
        sum1+=s[i][0];
        sum2+=s[i][1];
    }

    ave1 = sum1/10;
    ave2 = sum2/10;
    printf("average height = %d\n",ave1);
    printf("average weight = %d\n",ave2);
    
    return 0;
}