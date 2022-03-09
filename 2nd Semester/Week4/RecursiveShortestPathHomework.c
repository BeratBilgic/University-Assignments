#include <stdio.h>

int findPath(int arr[6][12], int x, int y);

int main(){
    int arr[6][12] = {
                    {1,0,1,1,1,0,0,1,0,1,1,0},
			        {1,0,1,1,1,1,1,0,1,0,0,0},
			        {1,1,1,1,1,1,1,0,1,0,1,0},
	             	{0,1,0,1,0,1,0,1,1,1,1,1},
			        {0,1,0,1,1,1,1,1,0,0,0,1},
			        {1,1,1,0,1,1,1,1,1,1,1,1},
    };
    for (int i = 0; i < 6; i++)
    {
       for (int j = 0; j < 12; j++)
       {
           printf("%d ",arr[i][j]);
       }
       printf("\n");
    }
    printf("\n");

    findPath(arr,0,0);
}

int findPath(int arr[6][12], int x, int y){

    if (x == 5 && y == 11)
    {
        printf("%d %d\n",x,y);
        return 1;
    }
    
    if (arr[x][y] == 1 && x < 6 && y < 12 && x > -1 && y > -1)
    {
        if (findPath(arr,x+1,y) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }else if(findPath(arr,x,y+1) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }else{
            return 0;
        }
        
    }else{
        return 0;
    }

}