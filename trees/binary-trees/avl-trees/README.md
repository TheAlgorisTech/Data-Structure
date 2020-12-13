# AVL trees
- Self-balancing **Binary Serach Trees (BST)**
- *Balance factor* is equal to difference between height of left and right subtree 
- *Balance factor* cannot be more than one for all nodes (i.e takes -1, 0, 1)
- *Balance factor* is calculated for each node in the tree
- **AVL** trees are smaller then **BST** (minimum height tree implies a faster **BST**
- **AVL** perfoms rotations on **BST** to form smaller trees



## Data Structure

```
struct Node {
				struct Node *left, *right;
				int data;
				int bf; // node height 
};

```


## Insertion
- Argument the standard **BST** insert operation to perform some re-balancing
- Operations for re-balancing
	- Left rotation
	- Right rotation

__Steps:__
- Perform standard **BST** insert for *w*
- Starting from w, tarvel up & find the first unbalanced node
- Re-balance the tree by performing appropriate rotations on the subtree, rooted by unbalanced node

### Rotations
	- Left of Left inbalance (simple rotation)

```
			X																T1
		 / 															 /  \
		T1				LL Rotation		 				T2   X
	 /
	T2
```
	- Left of Right inbalance (double rotation)
```
			X																	T2
		 / 												         /  \   
		T1 				LR Rotation		 				  T1   X
	   \
		 T2
```
	- Right Right Case (simple rotation)

```
			X            											T1
		 	 \          										 /  \
			  T1       RR Rotation		  	  X    T2 
	 		   \	
			 	  T2
```

	- Right Left Case

```
			X					   											T2
		 	 \          										 /  \
			  T1       RL Rotation		  	  X    T1
	 		 /	
		  T2
```

## Complexity
- Height of an **AVL** tree is always $O(log n)$
