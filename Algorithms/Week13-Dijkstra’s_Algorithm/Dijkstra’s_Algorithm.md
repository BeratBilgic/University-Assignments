# Dijkstra’s Algorithm

Dijkstra's algorithm finds the shortest paths between source and all other vertices, if path exists.

| Data structure used for the minimum edge weight    | Time Complexity |
| -------- | ------- |
| Adjacency matrix, linear searching, array  | O(V<sup>2</sup>)   |
| Adjacency list and binary heap | O(E*logV)     |

## Pseudocode
```
function dijkstra(G, S)
    for each vertex V in G
        distance[V] <- infinite
        previous[V] <- NULL
        If V != S, add V to Priority Queue Q
    distance[S] <- 0
	
    while Q IS NOT EMPTY
        U <- Extract MIN from Q //get and remove the node in Q with the smallest distance[ ]    
        for each unvisited neighbour V of U
            tempDistance <- distance[U] + edge_weight(U, V)
            if tempDistance < distance[V]
                distance[V] <- tempDistance
                previous[V] <- U
    return distance[], previous[]
```