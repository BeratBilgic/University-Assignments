#include <stdio.h>

int main()
{   
    int player,sign,input;
    char board [9]; 
    int count = 0;
    int winControl = 0;

    for (int i = 0; i < 9; i++)
    {
        board[i] = ' ';   
    }

    printf(" %c | %c | %c \n",board[0],board[1],board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[3],board[4],board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[6],board[7],board[8]);
    printf("\n"); 

    while( count < 9 )
    {    
        if (count % 2 == 0) //player move
        {
            player = 1;
            sign = 'X';
        }
        else
        {
            player = 2;
            sign = 'O';
        }
        if(player == 1)
        {
            printf("First player's turn ( X ) \n");
            scanf("%d",&input);
        }else
        {
            printf("Second player's turn ( O )\n");
            scanf("%d",&input);
        }
        if (1<=input && input<=9)
        {
            if(board[input-1] != 'X' && board[input-1] != 'O')
            {
                board[input-1] = sign;
                count++;
            }
        }
        else
        {
            printf("WRONG MOVE\n"); 
        }

        printf(" %c | %c | %c \n",board[0],board[1],board[2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n",board[3],board[4],board[5]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n",board[6],board[7],board[8]);
        printf("\n");  

        if( 3 < count && count < 10) //win control
        {
            for (int n = 0; n < 3; n++)
            {
                if ((board[n] == board[n+3] && board[n] == board[n+6]) && (board[n] == 'X' || board[n] == 'O') )
                {
                    winControl = 1;
                    count = 10;
                }
            }
            for (int m = 0; m < 9; m+=3)
            {
                if ((board[m] == board[m+1] && board[m] == board[m+2]) && (board[m] == 'X' || board[m] == 'O'))
                {
                    winControl = 1;
                    count = 10;
                }
            }
            if (board[0] == board[4] && board[4] == board[8] || board[2] == board[4] && board[4] == board[6])
            {
                winControl = 1;
                count = 10;
            }
        }
    }
    if (winControl == 1)
    {
        printf("**************************************\n");
        printf("*** CONGRATULATIONS PLAYER %d WON ****\n",player);
        printf("**************************************\n\n");
    }
    else
    {
        printf("************\n");
        printf("*** DRAW ***\n");
        printf("************\n\n");
    }
    
    return 0;
}