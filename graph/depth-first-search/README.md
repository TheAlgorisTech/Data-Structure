# Depth first search (DFS)
An algorithm for traversing or searching tree or graph data structures. **DFS** is typically used to traverse an entire graph. 

__Application:__
- Solving puzzles with only one solution, such as mazes
- Searching for solutions in artificial intelligence 
- Web Crawling
- Collect sample of graph nodes



## Complexity
- Takes time O ( | V | + | E | )

## Implementation
- Use **STACK** (LIFO) data structure with maxium size equal number of vertices

1. Select any vertex as starting point for traversal
2. Visit vertex & push it on to the **STACK**
3. Visit any one of the non-visited adjacent vertices of a vertex (top of stack & push it on to the stack)
4. Repeat the visiting step until there is no new vertex to be visited from the vertex which is at the top of the stack
5. When there is no new vertice to visit use **Back-Tracking** and pop one vertex from the **STACK**
6. Repeat steps 3, 4 and 5 until **STACK** becomes empty


## Type of edges in **ST**


| 	Type 		|	Description |
| :-------- | ----------: |
|		Tree edge | Edges which belong to the spanning tree itself	|
|		Forward edge |  Point from a node of the tree to one of its descendants	|
|		Backward edge | Point from a node to one of its ancestors		|
|		Cross edge | neither forward or backward edge		|




## Drawbacks
- DFS may suffer from non-termination

