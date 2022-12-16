#include "binary_trees.h"

/**
 * get_depth - measures the depth of a tree node
 * @tree: the node whose depth to measure
 * Return: the measured depth
 */
size_t get_depth(const binary_tree_t *tree)
{
	size_t  depth;

	if (tree == NULL)
		return (0);
	/* work backwards towards root */
	depth = get_depth(tree->parent);
	return (depth + 1);
}


/**
 * binary_tree_depth - measures the depth of a binary tree node
 * NOTE: the length of path from root to the node
 * @tree: pointer to the node of whose depth is to be measured
 * Return: the depth measured
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	/* don't include the node in calculation */
	return (get_depth(tree) - 1);
}
