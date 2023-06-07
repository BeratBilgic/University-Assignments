# Depth-first search (DFS) 

The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.

Time Complexity: Q(V+E)

## Pseudocode
```
DFS(G,v) ( v is the vertex where the search starts )
    Stack S := {};  ( start with an empty stack )
    for each vertex u, set visited[u] := false;
    push S, v;
    while (S is not empty) do
        u := pop S;
        if (not visited[u]) then
            visited[u] := true;
            for each unvisited neighbour w of u
                push S, w;
        end if
    end while
END DFS()
```

# Breadth-first search (BFS)

The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.

Time Complexity: Q(V+E)

## Pseudocode
```
BFS(G,v) ( v is the vertex where the search starts )
    Queue Q := {};  ( start with an empty queue )
    for each vertex u, set visited[u] := false;
    enqueue Q, v;
    while (Q is not empty) do
        u := dequeue Q;
        if (not visited[u]) then
            visited[u] := true;
            for each unvisited neighbour w of u
                enqueue Q, w;
        end if
    end while
END DFS()
```