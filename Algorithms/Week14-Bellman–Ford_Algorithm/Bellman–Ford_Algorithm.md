# Bellman–Ford Algorithm

Bellman Ford algorithm helps us find the shortest path from a vertex to all other vertices of a weighted graph.

It is similar to Dijkstra's algorithm but it can work with graphs in which edges can have negative weights.

| Time Complexity |  |
| -------- | ------- |
| Best Case Complexity   | O(E) |
| Average Case Complexity  | O(V*E)  |
| Worst Case Complexity | O(V*E)     |

## Pseudocode
```
function bellmanFord(G, S)
    for each vertex V in G
        distance[V] <- infinite
        previous[V] <- NULL
    distance[S] <- 0

    for each vertex V in G				
        for each edge (U,V) in G
            tempDistance <- distance[U] + edge_weight(U, V)
            if tempDistance < distance[V]
                distance[V] <- tempDistance
                previous[V] <- U

    for each edge (U,V) in G
        If distance[U] + edge_weight(U, V) < distance[V]
            Error: Negative Cycle Exists

    return distance[], previous[]
```