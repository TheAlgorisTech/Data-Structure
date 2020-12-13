# Shortest Path 

# Dijkstra algorithm
- Find shortest path from source to all vertices in the given graph
- Work on both directed and undirected graph
- Very similar to [Prim's Algorithm]
- Maintain two sets, one for vetices included in shortest and other for vertices not included yet


- Relaxation: $if d[u]+c(u,v) < d[v]$

## Algorithm
- Create a shortest path tree set that keeps track of vertices included in shortest path tree
- Assign distance value to all vertices in the input graph
				- Initialize all distance values as **INIFINITE**
				- Assign distance value as 0 for the source vertex
- While set created in step 1 doesn't include all vertices
				- Pick a vertex *u* not included in the set and has minimum distance value
				- Include *u* to the set
				- Update all instance values, iterate through all adjacent vertices.
								- For every adjacent vertex *v* apply, if sum of distance value of u (from source) & weight of edge *u-v*, is less than the distance value of *v*, then update the distance value of *v* **Relaxation**


## Complexity

- In case of complete graph it has $O(#V^2)$

## Drawbacks
- May fail to find shortest path when edges may have negative values


# Bellman-Ford algorithm
Computes shortest paths from a single source vertex to all of the other vertices in a weighted directed graph.

- Follow dynamic programming strategy
- Can handle graphs in which some of the edge weights are negative numbers
- Can detect and report the negative cycle


## Algorithm
- Initializes distances from the source to all vertices as infinite & distance to the source itself as 0
- Create and array of size $#V$ which all values as infinite except source distance
- Compute shortest distances and apply **RELAXATION**
- This step reports if there is a negative weight cycle in graph



## Drawbacks
- If a graph contains negative cycle that is reachable from the source, then there is no cheapest path
- Slower than Dijkstra algorithm

## Complexity

- Relax all edges, repeatedly relaxed for $#V - 1 $ time
- $O(#E*#V-1) ~ O(n^2)$
- In complete graph, when there is edge between every pair of vetices, time complexity is $O((n-1)*n(n-1)/2) ~ O(n^3)$



# Floyd-Warshall
- Find shortest path between every pairs of vertices
- Follow dynamic programming strategy


## Complexity
- $O(#V^3)$
