#include "binary_trees.h"


/**
 * binary_tree_size - measures the size of a binary tree
 * NOTE: i.e. the number of nodes in a tree
 * @tree: pointer to the to be measured tree's root node
 * Return: the size measured
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0); /* base case */
	/* get the number of nodes in left sub-tree */
	left = binary_tree_size(tree->left);
	/* get the number of nodes in right sub-tree */
	right = binary_tree_size(tree->right);
	/* add the current node to the sum  */
	return (left + 1 + right);
	/* same as calling the fns directly in the return + 1 */
}
