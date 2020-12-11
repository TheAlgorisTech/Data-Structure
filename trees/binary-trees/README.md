# Binary Search Tree
Binary tree is a specialized form of tree in which each node has at most two children, named left & right.
The value in each node is greater than all of the values in its left subtree & less than all of the values in its right subtree.

- Each node in the tree has exactly one parent
- Topmost node is called the *root*
- Nodes without children are called *leaf nodes* (a.k.a leafes)

![gif](http://108.61.119.12/wp-content/uploads/2014/10/binary-tree-1-search.gif)

## Properties
- The maximum number of nodes at any level is $2^{level}$
- The maximum number of nodes of height *h* is $\sum_{i=0}^{h}2^i$ (Geometric series)
- The minimum number of nodes of height h is $h+1$
- Given maximum number of nodes the minimum height of tree is $h=\lceil log_2(h+1)-1 \rceil$
- Given minmum number of nodes the maximum height of tree is $h=\rmtext{number of nodes} - 1$

## Binary tree types

| Type | Description | Max nodes | Min nodes | Min height | Max height |
| :--- | :---------: | :-------: | :-------: | :--------: | ---------: |
| Full/proper/strict | Nodes cotaines either 0 or 2 children| 2^h-1 | 2h+1 | log_2(h+1



## Operations

### Insertion

- Inserting new node in the proper positon is important to maintain search tree property
- It's more efficient to implement the algorithm iteratively because the algorithm is tail recursion

```
If tree is empty
				insert node at the root
Otherwise:
				If the new value is less than the current node value:
								insert the new value in the left subtree of the current node
				Otherwise:
								insert the new value in the right subtree of the current node
```



### Deletion
- Deleting a node from the middle of the tree require connecting it's subtrees to the rest of the tree
- There is three cases:
				- Deleting node with no children
				- Deleting node with one child
				- Deleting node with two child


### Searching
Searching tree for a particular value is simple due to ordering imposed on binary search tree.

```
If tree empty:
				value is not in the tree
Otherwise:
				If value is equal to the value in the current node:
								found value
				Otherwise:
								If value is less than value in the current node:
												search left subtree
								Otherwise:
												search right subtree
```

### Tree Traversals
Traversal is when all of the nodes in a tree are examined. There are several different orders in which the nodes may be traversed:
	- pre-order: examines value in the node & then recursively traverses the left & right subtrees
	- in order: traverses left subtree, then examines the value in the node and traverses the right subtree last
	- post-order: traverses the left and right subtrees first and examines the node's value last
	- breadth-first: examines the nodes of the tree level by level	
All traversals start at the root of the tree


