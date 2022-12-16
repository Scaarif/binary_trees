#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using
 * in-order trversal, also referred to as: LNR
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to be called for each node,
 * takes the value of the node as a parameter
 * Return: Nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func) /* == LNR */
	{
		/* traverse to the left subtree */
		binary_tree_inorder(tree->left, func);
		/* traverse root node (N) */
		func(tree->n);
		/* traverse the right subtree */
		binary_tree_inorder(tree->right, func);
	}
}
