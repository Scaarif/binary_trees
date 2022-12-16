#include "binary_trees.h"

/**
 * get_height - measures the height a tree from the given node
 * @tree: the node to start measuring from
 * Return: the measured height
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	/* check that tree is defined */
	if (tree == NULL)
		return (0);
	/* get the sub-tree depths */
	l_height = get_height(tree->left);
	r_height = get_height(tree->right);
	/* take the larger (deeper) of the two, add current node */
	if (l_height > r_height)
		return (l_height + 1);
	return (r_height + 1); /* otherwise */
}


/**
 * binary_tree_height - measures the height of a binary tree
 * NOTE: the length of path from root to deepest node
 * @tree: pointer to the root node of the tree to be measured
 * Return: the height measured
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	/* exclude start node from measurement */
	return (get_height(tree) - 1);
}
