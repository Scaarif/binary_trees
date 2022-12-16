#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using
 * pre-order trversal, also referred to as: NLR
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to be called for each node,
 * takes the value of the node as a parameter
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func) /* == NLR */
	{
		/* start at the root node (N) */
		func(tree->n);
		/* traverse to the left subtree */
		binary_tree_preorder(tree->left, func);
		/* traverse the right subtree */
		binary_tree_preorder(tree->right, func);
	}
}
