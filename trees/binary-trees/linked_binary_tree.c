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



typedef struct BinNode {

				int value;
				BinNode *LeftNode;
				BinNode *RightNode;
} BindNode;




BinNode *empty()
{
				BindNode *tree = (BindNode *) malloc(sizeof(BindNode));
				tree->LeftNode = NULL;
				tree->RightNode = NULL;
				return tree;
}




int main()
{
				BindNode *tree = empty();


}
