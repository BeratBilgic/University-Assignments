#include <stdio.h>

int main()
{
    char str[10][20],que[10][20];
    for ( int j = 0; j < 10; j++)
    {
        scanf("%s",str[j]);
        for (int i = 0; i < 10; i++)
        {   
            que[j][i] = str[j][i];  
        }    
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (str[i][0] < que[j][0])
            {
                for (int k = 0; k < 10; k++)
                {      
                    que[j][k] = str[i][k];  
                }
            }
        }
        
        
    }
    

    printf("**********\n");
    for (int k = 0; k < 10; k++)
    {
        printf("%s\n",que[k]);
    }
    
    
    return 0;
}