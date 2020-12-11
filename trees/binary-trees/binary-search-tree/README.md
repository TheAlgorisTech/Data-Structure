# Binary search tree
Binary tree is a specialized form of tree in which each node has at most two children, named left & right.
The value in each node is greater than all of the values in its left subtree & less than all of the values in its right subtree.




![gif](http://108.61.119.12/wp-content/uploads/2014/10/binary-tree-1-search.gif)



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
