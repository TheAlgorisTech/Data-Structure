# Graph adjacency lists


| Type | Size |
| :--- | ----:|
| Adjacency List | Dynamic |
| Adjacency List | Static |


## Adjacency Lists
 - Represent sparse graphs (i.e number of edges is much smaller than number of vertices) by using *linked lists*
 - Require pointers
 - They are the right data structure for most applications of graphs


## Data Structure
 - Consists of an array of number of vertex (one for each vertex in V)
 - Each vertex in the graph is assiociated with its neighboring vertices and edges
 - Adjacency lists represent the edges of a graph


### Pros
 - Faster to find the defre of a vertex than Adjacency matrix
 - Less memory on small graphs
 - Faster to traverse graph $O(m+n)$ vs $O(n^2)$ for Adjacency matrix


### Cons
 - Makes it harder to verify whether a given edge belong to graph G
