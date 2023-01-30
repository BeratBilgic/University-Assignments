#include <stdio.h>
#include <stdlib.h>

#define N 5

/*
write a program that prints out
the degree of each vertex in the 
undirected graph which is represented
by adjacency matrix
*/

int findDegree(int matrix[N][N], int vert){
    int numDegree = 0;
    for (int i = 0; i < N; i++){
        numDegree+=matrix[vert][i];
    }

    return numDegree;
}

void printAllDegree(int matrix[N][N]){
    int sumOfDegrees = 0, degree;
    for (int i = 0; i < N; i++){
        degree = findDegree(matrix, i);
        printf("Degree of vertex %d is %d\n",i+1 , degree);
        sumOfDegrees+=degree;
    }

    printf("Sum of the degrees: %d\n", sumOfDegrees);
}

int findEdgesNum(int matrix[N][N]){
    int edges = 0;
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            edges+=matrix[i][j];
        }
    }

    return edges;
}

int main(){
    int undirectedMatrix[N][N] ={
            {0,1,1,1,0},
            {1,0,0,1,0},
            {1,0,0,1,1},
            {1,1,1,0,1},
            {0,0,1,1,0}
            };

    printAllDegree(undirectedMatrix);
    printf("The number of edges: %d\n", findEdgesNum(undirectedMatrix));

    return 0;
}