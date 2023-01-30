#include <stdio.h>

int findPath(int arr[6][12], int x, int y);
int r_move(int arr[6][12], int x, int y);
int l_move(int arr[6][12], int x, int y);
int d_move(int arr[6][12], int x, int y);
int u_move(int arr[6][12], int x, int y);

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
        if (r_move(arr,x+1,y) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }else if(d_move(arr,x,y+1) == 1)
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

int r_move(int arr[6][12], int x, int y){
    if (x == 5 && y == 11)
    {
        printf("%d %d\n",x,y);
        return 1;
    }
    
    if (arr[x][y] == 1 && x < 6 && y < 12 && x > -1 && y > -1)
    {
        if (r_move(arr,x+1,y) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }else if(d_move(arr,x,y+1) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }
        else if(u_move(arr,x,y-1) == 1)
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
int l_move(int arr[6][12], int x, int y){
    if (x == 5 && y == 11)
    {
        printf("%d %d\n",x,y);
        return 1;
    }
    
    if (arr[x][y] == 1 && x < 6 && y < 12 && x > -1 && y > -1)
    {
        if (d_move(arr,x,y+1) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }else if(l_move(arr,x-1,y) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }
        else if(u_move(arr,x,y-1) == 1)
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
int d_move(int arr[6][12], int x, int y){
    if (x == 5 && y == 11)
    {
        printf("%d %d\n",x,y);
        return 1;
    }
    
    if (arr[x][y] == 1 && x < 6 && y < 12 && x > -1 && y > -1)
    {
        if (d_move(arr,x,y+1) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }else if(r_move(arr,x+1,y) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }
        else if(l_move(arr,x-1,y) == 1)
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
int u_move(int arr[6][12], int x, int y){
    if (x == 5 && y == 11)
    {
        printf("%d %d\n",x,y);
        return 1;
    }
    
    if (arr[x][y] == 1 && x < 6 && y < 12 && x > -1 && y > -1)
    {
        if (r_move(arr,x+1,y) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }else if(u_move(arr,x,y-1) == 1)
        {
            printf("%d %d\n",x,y);
            return 1;
        }
        else if(l_move(arr,x-1,y) == 1)
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
