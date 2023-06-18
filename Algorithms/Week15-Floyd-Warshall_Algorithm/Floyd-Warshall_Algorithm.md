# Floyd-Warshall Algorithm

Floyd-Warshall Algorithm is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph. This algorithm works for both the directed and undirected weighted graphs. But, it does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative).

Time Complexity = O(n<sup>3</sup>) 

## Pseudocode
```
function floydWarshall(G) ( G is matrix )
    n = no of vertices
    A = matrix of dimension n*n
    for k = 1 to n
        for i = 1 to n
            for j = 1 to n
                A^(k)[i, j] = min (A^(k-1)[i, j], A^(k-1)[i, k] + A^(k-1)[k, j])
    return A
```