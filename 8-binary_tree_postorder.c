#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using
 * post-order trversal, also referred to as: LRN
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to be called for each node,
 * takes the value of the node as a parameter
 * Return: Nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func) /* == LNR */
	{
		/* traverse to the left subtree */
		binary_tree_postorder(tree->left, func);
		/* traverse the right subtree */
		binary_tree_postorder(tree->right, func);
		/* root node (N) */
		func(tree->n);
	}
}
