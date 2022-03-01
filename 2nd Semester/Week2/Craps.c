#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int x,y,sum,point;
    printf("\nRoll the dice\n");
    x = rand() % 6 + 1;
    y = rand() % 6 + 1;
    printf("%d %d\n",x,y);
    sum = x + y;
    while (1){
        if (sum == 7 || sum == 11 ){
            printf("YOU WON\n");
            point += sum;
            break;
        }else if(sum == 2 || sum == 3 || sum == 10){
            printf("GAME OVER\n");
            point += sum;
            break;
        }
        while (sum != 7){
            printf("Roll the dice\n");
            x = rand() % 6 + 1;
            y = rand() % 6 + 1;
            printf("%d %d\n",x,y);
            sum = x + y;
            point += sum;
        }
        printf("YOU WON\n");
        break;
    }
    printf("Your point = %d\n",point);

    return 0;
}