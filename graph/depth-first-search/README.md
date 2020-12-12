# Depth first search (DFS) traversal
- Use **STACK** (LIFO) data structure with maxium size equal number of vertices


### Type of edges


| 	Type 		|	Description |
| :-------- | ----------: |
|		Tree edge | -		|
|		Forward edge | -		|
|		Backward edge | -		|
|		Cross edge | -		|


### Implementation
1. Select any vertex as starting point for traversal
2. Visit vertex & push it on to the **STACK**
3. Visit any one of the non-visited adjacent vertices of a vertex (top of stack & push it on to the stack)
4. Repeat the visiting step until there is no new vertex to be visited from the vertex which is at the top of the stack
5. When there is no new vertice to visit use **Back-Tracking** and pop one vertex from the **STACK**
6. Repeat steps 3, 4 and 5 until **STACK** becomes empty



