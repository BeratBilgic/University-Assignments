#include <stdio.h>
#include <stdlib.h>

#define N 5

/* 
write a function that returns true if 
there is a path between two given vertices 
in a diagram which is represented by matrix, false otherwise
*/

int existsPathTwoVert (int diagram[N][N], int source, int dest){
    if (diagram[source][dest]){
        return 1;
    }

    for (int i = 0; i < N; i++)
        {
            if (diagram[source][i] && existsPathTwoVert(diagram, i, dest))
            {
                return 1;
            }
        }

    return 0;
}

void checkPath (int diagram[N][N], int source, int dest){
    if (existsPathTwoVert(diagram, source-1, dest-1))
        printf("\n%d -> %d path exists\n", source, dest);
    else
        printf("\n%d -> %d path not exists\n", source, dest);
}

int main(){
    int diagram[N][N] ={
            {0,1,1,0,0},
            {0,0,0,1,0},
            {0,1,0,1,1},
            {0,0,0,0,1},
            {0,0,0,0,0}
            };

    checkPath(diagram, 1, 4);
    checkPath(diagram, 5, 1);
    checkPath(diagram, 2, 3);
    checkPath(diagram, 2, 5);

    return 0;
}