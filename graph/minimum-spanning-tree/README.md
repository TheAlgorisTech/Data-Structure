# Minimum spanning tree (MST)

Spanning tree is a sub-graph of a given graph, that contains the same number of graph vertices but with reduced number of edges.
Each graph can have at most $C^{|V|-1}_{|Edges|}-\textrm{number of cycles}$ spanning tree. Every connected & undirected graph has at least one spanning tree. 



# Properties
- Number of vertices in spanning tree is equal to the number of vertices in a given graph
- Number of edges in spanning tree is eqaul to number of vertices in given graph minus 1, |V| - 1
- Spanning tree should not contain any cycle
- Spanning tree should not be disconnected
- Adding one edge to spanning tree will create a cycle
- Removing one edge from spanning tree it will become disconnected
- If each edge has distinct weight then there will only one and unique **MST**
- Complete undirected graph can have $n^{n^{n-2}}$ of **ST**
- From complete graph by removing max(e-n+1) edges we can construct **ST**




# Algorithms to detect MST

| Algorithms |  Description | Complexity |
| :--------- |  :---------: | ---------: |
| Kruskals   | 	    Find minimum cost **ST**       |  $ O(#V^2)$ |
| Prims   	 | 	    Find minimum cost **ST**       |		$O(#V^2)$ or $O(#Elog#V) $ or $O(#E+#Vlog#V) $|



# Prim's (a.k.a Jarník's)
Greedy algorithm that finds a **MST** for a weighted undirected graph.
operates by building this tree one vertex at a time
from an arbitrary starting vertex, at each step adding the cheapest possible connection from the tree to another vertex

- Initially select smallest weighted edge from a graph 
- Always select the smallest connected edge

## Complexity
- Time complexity of Prim's algorithm depends on the data structures used for the graph and for ordering the edges by weight

## Advantages
- Fast for sparse graphs


# Kruskals
Finds a minimum spanning forest of an undirected edge-weighted graph

- Remove all the loops and parallel edges
- Keep an edge with minimum weight from parallel edges
- May find **ST** for disconnected graph


- Create a forest *F*, where each vertex in the graph is a separate **tree**
- Create a set *S* containing all the edges in the graph
- While *S* is nonempty and *F* is not yet spanning
  - Remove edge with minimum weight from *S*
  - if removed edge connects two different trees then add it to the forest *F*, combining two trees into a single tree

