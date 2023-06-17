# Prim's algorithm

The steps for implementing Prim's algorithm are as follows:

- Initialize the minimum spanning tree with a vertex chosen at random.
- Find all the edges that connect the tree to new vertices, find the minimum and add it to the tree
- Keep repeating step 2 until we get a minimum spanning tree

| Data structure used for the minimum edge weight    | Time Complexity |
| -------- | ------- |
| Adjacency matrix, linear searching, array  | O(V<sup>2</sup>)   |
| Adjacency list and binary heap | O(E*logV)     |

## Pseudocode
```
Prim(G):
    Initialize an empty set called MST (minimum spanning tree)
    Initialize an empty priority queue called pq (priority queue)
    Select a starting node arbitrarily and mark it as visited
    
    Add all edges connected to the starting node to pq
    
    while pq is not empty:
        currentEdge = pq.removeMin()  // Remove the edge with the minimum weight from pq
        currentNode = currentEdge.endNode
        
        if currentNode is not visited:
            Add currentEdge to MST
            Mark currentNode as visited
            
            for each edge in G connected to currentNode:
                if the other endNode of edge is not visited:
                    Add edge to pq
    
    return MST
```