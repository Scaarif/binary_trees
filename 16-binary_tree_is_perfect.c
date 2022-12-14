#include "binary_trees.h"

/**
 * left - returns the left-subtree's height
 * @tree: pointer to start node
 * Return: the height
 */
size_t left(const binary_tree_t *tree)
{
	size_t h;

	if (tree == NULL)
		return (0);
	h = left(tree->left);
	return (h + 1);
}

/**
 * right - returns the right-subtree's height
 * @tree: pointer to start node
 * Return: the height
 */
size_t right(const binary_tree_t *tree)
{
	size_t h;

	if (tree == NULL)
		return (0);
	h = right(tree->right);
	return (h + 1);
}

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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * NOTE: a variant of a full tree that is also balanced (k == 0)
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 is true and 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* traverse through the tree nodes */
	if (tree == NULL)
		return (0);
	/* check that tree is full and with a balance factor of 0 */
	return (is_full(tree) && !(left(tree) - right(tree)));
}
