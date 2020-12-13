# Graph 

- Non-linear data structure consisting of nodes and edges
- Provides a language for talking about the properties of relationships

![gif](https://cdn-images-1.medium.com/max/1600/1*heR0By4G5GbpJ6ZaftJLRQ.gif)

- Graphs are important because they can be used to represent essentially any relationship
	- Transportation systems
	- Human interactions
	- Telecomunication networks
	- Electronic circuits
- Trees are restricted types of graphs



## Terminologies 
- Vertices V (a.k.a Vertex)
	- Units of the graph
	- end vertices: two vertices joined by edge 
- Edges E (a.k.a arcs)
	- Drawn or used to connect two nodes of the graph
	- Ordered/unordered pairs of vertices from V
	- Can connect two nodes in any possible way


- Size of graph: number of edges contained in graph
- Order of graph: number of vertices contained in graph
- Adjacent: if there is an edge between vertex A and B then both vertex are adjacent
- Incident: edge is incident on a vertex if the vertex is one of the endpoints of that edge
- Degree: total number of edges connected to a vertex
- Indegree: total number of incomming edges connected to a vertex (Only in directed graph) 
- Outdegree: total number of outcomming edges from the connected vertex (Only in directed graph) 
- Path: sequence of alternate vertices and edges that starts at a vertex and ends at other vertex such that each edge is incident to its predecessor and sucessor vertex

<!-- Circuit path when the path is not empty, source and destination are same vertex -->
<!-- Simple path when path contains distinct edges -->
<!-- Elementary path when all endpoints are distinct -->



__Notation (u,v) indicates that there is an edge from vertex u to vertex v__

## Properties

- Maximum number of vertices in undirected graph is $C^2_{|V|}$
- Maximum number of vertices in directed graph is $2*C^2_{|V|}$


### Sparse & Density graphs
- Graph density is a metric that tell us how "full" a graph is, in terms of the number of edges that it possess, and in relation to the number of its vertices, D(V,E) varies between 0 and 1
	-	Density of undirected graph is equal to number of edges divides my the maximum number of vertices
- Sparse graph is a graph whose density is in the lower range of the density's codomain i.e $0 \le D < \frac{1}{2}$
	

<!-- | Types of Graph | Description |
| :------------- | ----------: |
| Undirected 	| <ul><li>No direction</li><li> Unordered nodes</li></ul>|
| Directed      | <ul><li>Edges has direction</li><li> Ordered nodes</li></ul>|
| Connected | <ul><li>No direction</li><li> Unordered nodes</li></ul>|
| Disconnected | At least one node is not reachable|
| Weighted | <ul><li>Each edge is assigned a numerical value</li><li>Unweighted graph all edges have equal weight</li><ul>|
| Complete | There is edge to each other node|
| Cyclic |  <ul><li>Contains at least one cycle</li><li>Opposit to acyclis graphs</li></ul>|
| Directed Asyclic (DAG) | <ul><li>Arise naturally in scheduling problems</li><li>Directed graph with no cycle</li></ul>|
| Labeled/Unlabeled | Each vertex is assigned a unique name | -->


## Graph traversal
- Technique used for a searching vertex in a graph
- Help to decide the order of vertices visited in the search process
- Finds edges in the search process without creating loops a.k.a **Spanning Tree**


<!--| Technique | Implementation |
| :-------- | -------------: |
|  BFS			|				-				 |
|  DFS 			|				-				 |-->



## Detect cycle in directed graph
- Use **STACK** data structure
	- insert vertex if not visited
	- pop out vertex if dead end vertex
- Use flag to mark if a vertex is visited or not
	- -1 univisited
	- 0 visited & in **STACK**
	- 1 visited & popped out from **STACK**
- Use visited set


- Use parent map (map each vertex to it's parent)
```
struct VertexMapParent {
		struct Vertex child;
		struct Vertex Parent;
	}
```

## Detect cycle undirected graph
- Use **QUEUE** data structure

