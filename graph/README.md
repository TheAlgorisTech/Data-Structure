# Graph 

<<<<<<< HEAD
- Non-linear data structure consisting of nodes and edges
=======
![gif](https://cdn-images-1.medium.com/max/1600/1*heR0By4G5GbpJ6ZaftJLRQ.gif)

>>>>>>> efdfd0b83919573dbbec2fea3de4002a707ea45d
- Graphs are important because they can be used to represent essentially any relationship
	- Transportation systems
	- Human interactions
	- Telecomunication networks
	- Electronic circuits
- Trees are restricted types of graphs



## 1. Graph Theory
- Provides a language for talking about the properties of relationships
- Graph G is defined by a set of:
	- Vertices V (a.k.a Vertex)
		- Units of the graph
	- Edges E (a.k.a arcs)
		- Drawn or used to connect two nodes of the graph
		- Ordered/unordered pairs of vertices from V
		- Can connect two nodes in any possible way

<<<<<<< HEAD
- Notation (u,v) indicates that there is an edge from vertex u to vertex v

=======
<!---
>>>>>>> efdfd0b83919573dbbec2fea3de4002a707ea45d
| Types of Graph | Description |
| :------------- | ----------: |
|	 Null    | No edges in the graph |
| Trivial	| <ul><li>Single vertex</li><li> Smallest graph</li></ul>|
| Undirected 	| <ul><li>No direction</li><li> Unordered nodes</li></ul>|
| Directed      | <ul><li>Edges has direction</li><li> Ordered nodes</li></ul>|
| Connected | <ul><li>No direction</li><li> Unordered nodes</li></ul>|
| Disconnected | At least one node is not reachable|
| Weighted | <ul><li>Each edge is assigned a numerical value</li><li>Unweighted graph all edges have equal weight</li><ul>|
| Complete | There is edge to each other node|
| Cyclic |  <ul><li>Contains at least one cycle</li><li>Opposit to acyclis graphs</li></ul>|
| Directed Asyclic (DAG) | <ul><li>Arise naturally in scheduling problems</li><li>Directed graph with no cycle</li></ul>|
| Labeled/Unlabeled | Each vertex is assigned a unique name |
--->

## 2. Graph data structure
Two basic choices are
   - Adjacency matrices
   - Adjacency lists
 
### 2.1 Adjacency Matrix
  - Graph repsented with a matrix
  - Representation easier to implement and follow
  - Faster to test if a relation exist in graph G
  - Edge insertion/deletion with constant time complexity O(1)
  - Use excessive space for graphs with many vertices & relatively few edges

### 2.2 Adjacency Lists
 - Represent sparse graphs by using *linked lists*
 - Require pointers
 - They are the right data structure for most applications of graphs
 - Faster to find the defre of a vertex than Adjacency matrix
 - Less memory on small graphs
 - Faster to traverse graph $O(m+n)$ vs $O(n^2)$ for Adjacency matrix
 - Makes it harder to verify whether a given edge belong to graph G













































