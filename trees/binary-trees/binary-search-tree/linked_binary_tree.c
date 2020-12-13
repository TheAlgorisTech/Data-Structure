/*
 * =====================================================================================
 *
 *       Filename:  linked_binary_tree.c
 *
 *    Description: Linked binary search tree
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>



typedef struct BinNode{
				int value;
				struct BinNode *LeftNode;
				struct BinNode *RightNode;
} BinTree;




BinTree *empty()
{
				BinTree *tree = (BinTree *) malloc(sizeof(BinTree));
				tree->LeftNode = NULL;
				tree->RightNode = NULL;
				return tree;
}


int isempty(BinTree *tree)
{
	return (tree==NULL) ? 1: 0;
}


/*************************************************
 *************************************************
 *****************  Operations *******************
 *************************************************
 *************************************************
 */


BinTree *insertNode(BinTree *tree, int v)
{
	/*
	 * Insert node to a tree
	 *
	 */

	BinTree *current;
	BinTree **link;

	// Point to the root adress
	link =&tree; 

	// While pointer didn't arrive to final leaf continue traversal
	while ( (current=*link) != NULL)
	{
		// if current value is less than inserted value go left
		if (v < current->value ) link = &current->LeftNode;
		else
		{
			link = &current->RightNode;
		}
	}
	// Add new node (final leaf) with current value to the tree
	current = (BinTree *) malloc(sizeof(BinTree));
	current->value = v;
	current->LeftNode = NULL;
	current->RightNode = NULL;
	*link = current;
	return tree;
}



//destroy_tree
BinTree *deleteNode(BinTree *tree)
{
		return tree;
}



BinTree *findValue(BinTree *tree, int v)
{
	/*
	 * Return pointer to the tree node containing the value
	 */
	BinTree *current;
	BinTree **link;
	
	// Start from the root
	link = &tree; 
	while ((current=*link) != NULL && current->value != v)
		{
			if (v < current->value)
			{
				link = &current->LeftNode;
			}
			else
			{
				link = &current->RightNode;
			}
		}
		if (current != NULL){
			printf("Value is found\n");
			return current;
		}
		else 
		{
			printf("Value not found\n");
			return NULL;
		}
}



void traversePreOrder(BinTree *tree)
{

	if (tree == NULL) return ;

	printf("%d\n", tree->value);

	traversePreOrder(tree->LeftNode);
	traversePreOrder(tree->RightNode);

}




int main()
{

		BinTree *tree;
		tree=insertNode(tree,40);
		tree=insertNode(tree,10);
		tree=insertNode(tree,30);
		tree=insertNode(tree,50);
		printf("Root Value %d\n", tree->value);
		printf("Left Node Value %d\n", tree->LeftNode->value);
		printf("Right Node Value %d\n", tree->LeftNode->RightNode->value);

		return EXIT_SUCCESS;

}
