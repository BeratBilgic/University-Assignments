# Dijkstra’s Algorithm

Dijkstra's algorithm finds the shortest paths between source and all other vertices, if path exists.

| Data structure used for the minimum edge weight    | Time Complexity |
| -------- | ------- |
| Adjacency matrix, linear searching, array  | O(V<sup>2</sup>)   |
| Adjacency list and binary heap | O(E*logV)     |

## Pseudocode
```
function Dijkstra(Graph, source):
    for each vertex v in Graph:
        dist[v] := infinity
        previous[v] := undefined
    dist[source] := 0
    Q := the set of all nodes in Graph
    while Q is not empty:
        u := node in Q with smallest dist[ ]
        remove u from Q
        for each neighbor v of u:
            alt := dist[u] + dist_between(u, v)
            if alt < dist[v]
                dist[v] := alt
                previous[v] := u
    return previous[ ], dist[ ]
```