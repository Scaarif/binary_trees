#include "binary_trees.h"

/**
 * is_full - does the actua checking
 * @tree: pointer to the tree's root node
 * Return: 1 if true and 0 otherwise
 */
int is_full(const binary_tree_t *tree)
{
	int left, right;

	/* end of tree / subtree */
	if (tree == NULL)
		return (1);
	/* exactly 1 child */
	if ((tree->left || tree->right) && (!(tree->left && tree->right)))
		return (0);
	/* traverse the left and right sub-trees of tree */
	left = is_full(tree->left);
	right = is_full(tree->right);
	/* return whichever is 0 */
	if (left < right)
		return (left);
	return (right); /* & 1 otherwise */
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 is true and 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* traverse through the tree nodes */
	if (tree == NULL)
		return (0);
	return (is_full(tree));
}
