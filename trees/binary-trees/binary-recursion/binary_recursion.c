/*
 * =====================================================================================
 *
 *       Filename:  binary_recursion.c
 *
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>



struct node {
				// Node value
				int nvalue;
				struct node *left, *right;
};


struct node *create(){
				
				struct node *newnode = (struct node *) malloc(sizeof(struct node));

				int value;

				
				printf("Enter -1 to stop insertioni: \n");
				scanf("%d", &value);
				

				if (value == -1){
								printf("Stop inserting nodes\n");
								return NULL;
				}

				newnode->nvalue = value;

				printf("Enter left child of %d\n", value);
				newnode->left = create();


				printf("Enter right child of %d\n", value);
				newnode->right = create();


				return newnode;
}




void inOrder(struct node *root)
{
		/*
		 * Traverse left part of the tree then root and right
		 */

		if (root == NULL) {return ;}
		inOrder(root->left);
		printf("%d", root->nvalue);
		inOrder(root->right);

}




void preOrder(struct node *root)
{
		/*
		 * Traverse tree in this order root left right
		 * print tree top down
		 */

		if (root == NULL) {return ;}
		printf("%d", root->nvalue);
		preOrder(root->left);
		preOrder(root->right);

}



void postOrder(struct node *root)
{
	/* 
	 * Traverse tree with the following order Left Right Root
	 * print tree upside down
	 */
		if (root == NULL) {return ;}
		postOrder(root->left);
		postOrder(root->right);
		printf("%d", root->nvalue);

}

int main(){

				struct node *root;

				root = create();

				preOrder(root);
				printf("\n");
				postOrder(root);
				printf("\n");
				inOrder(root);
				printf("\n");

				return EXIT_SUCCESS;
}
