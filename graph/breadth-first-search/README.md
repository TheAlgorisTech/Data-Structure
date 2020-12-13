# Breadth first search (BFS)
- An algorithm for traversing or searching tree or graph data structures
- Uses the opposite strategy of **depth-first search (DFS)**

## Properties
- Start traversing graph from any node
- Use **QUEUE** (FIFO) data structure

## Complexity
- Can be expressed as O( | V | + | E | ), since every vertex and every edge will be explored in the worst case

## Implementation
1. Define a **QUEUE** of size total number of vertices in the graph
2. Select any vertex as starting point
3. Visit vertex & insert it into **QUEUE**
4. Visit all non-visited *adjacent* vertices of the current vertex (which is at the front of the **QUEUE**) & insert them into the **QUEUE**
5. When there is no new vertex to be visited from the vertex which is at front of the **QUEUE** then delete that vertex
6. Repeat step 4 and 5 until queue becomes empty
7. When **QUEUE** becomes empty, then produces final spanning tree by removing unused edges from the graph

