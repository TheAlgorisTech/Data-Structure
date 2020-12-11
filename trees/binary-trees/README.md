# Binary Search Tree
Binary tree is a specialized form of tree in which each node has at most two children, named left & right.

- Each node in the tree has exactly one parent
- Topmost node is called the *root*
- Nodes without children are called *leaf nodes* (a.k.a leafes)


## Properties
- The maximum number of nodes at any level is $2^{level}$
- The maximum number of nodes of height *h* is $\sum_{i=0}^{h}2^i$ (Geometric series)
- The minimum number of nodes of height h is $h+1$
- Given maximum number of nodes the minimum height of tree is $h=\lceil log_2(n+1)-1 \rceil$
- Given minmum number of nodes the maximum height of tree is $h=n - 1$

## Binary tree types

| Type | Description | Max nodes | Min nodes | Min height | Max height |
| :--- | :---------: | :-------: | :-------: | :--------: | ---------: |
| Full/proper/strict | Nodes cotaines either 0 or 2 children| 2^h-1 | 2h+1 | \lceil log_2(n+1) \rceil -1 | (n-1)/2 |
| Complete | All levels are completely filled and last level has nodes as left as possible (filled from left to right)| 2^h +1 | 2^h | \lceil log_2(n+1) \rceil -1 | log(n) |
| Perfect | All internal nodes have 2 children & all leaves are at same level | - | - | - | - | - |
| Degenerate | All internal nodes have only one child | - | - | - | - | - |

- __Maximum nodes are the same in all binaries trees__
- __Every perfect binary tree can be complete and full binary tree__
- __Degenerate binary tree is a.k.a left (resp. right) skewed binary tree when it only contains left (resp. right) nodes__


## Operations

### Insertion

### Deletion

### Tree Traversals
Traversal is when all of the nodes in a tree are examined. There are several different orders in which the nodes may be traversed:

- pre-order: examines value in the node & then recursively traverses the left & right subtrees
- in order: traverses left subtree, then examines the value in the node and traverses the right subtree last
- post-order: traverses the left and right subtrees first and examines the node's value last
- breadth-first: examines the nodes of the tree level by level	

__All traversals start at the root of the tree__


