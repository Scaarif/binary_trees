#include "binary_trees.h"

/**
 * left - returns the left-subtree's height
 * @tree: pointer to start node
 * Return: the height
 */
size_t left(const binary_tree_t *tree)
{
	size_t l_height;

	if (tree == NULL)
		return (0);
	l_height = left(tree->left);
	return (l_height + 1);
}


/**
 * right - returns the right-subtree's height
 * @tree: pointer to start node
 * Return: the height
 */
size_t right(const binary_tree_t *tree)
{
	size_t r_height;

	if (tree == NULL)
		return (0);
	r_height = right(tree->right);
	return (r_height + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * NOTE: the difference in height between left and right sub-trees
 * @tree: pointer to the root node of the tree to be measured
 * Return: the balance factor measured
 */
size_t binary_tree_balance(const binary_tree_t *tree)
{
	/* exclude start node from measurement */
	return (left(tree) - right(tree));
}
