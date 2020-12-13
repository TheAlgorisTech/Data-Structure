# Breadth first search (BFS) traversal
- Start traversing graph from any node
- Use **QUEUE** (FIFO) data structure

### Implementation
1. Define a **QUEUE** of size total number of vertices in the graph
2. Select any vertex as starting point
3. Visit vertex & inert it into **QUEUE**
4. Visit all the non-visited *adjacent* vertices of the vertex (which is at the front of the **QUEUE**) & insert them into the **QUEUE**
5. When there is no new vertex to be visited from the vertex which is at front of the **QUEUE** then delete that vertex
6. Repeat step 4 and 5 until queue becomes empty
7. When **QUEUE** becomes empty, then produces final spanning tree by removing unused edges from the graph



```

function breadth_fist_searchi(Graph G, Vertex VSRC)

	mark VSRC as visited
	INSERT VSRC to QUEUE HEAD

	WHILE (QUEUE NOT EMPTY)
				START EXPLORING VSRC
				while NOT VSRC EXPLORED
					INSERT adjacent UNVISITED vertices TO QUEUE TAIL

				REMOVE VSRC FROM QUEUE HEAD

```
