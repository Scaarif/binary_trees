#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * NOTE: a leaf has no children
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL)
	{
		/* check that it has no left or right */
		if (node->left != NULL)
			return (0);
		if (node->right != NULL)
			return (0);
		return (1); /* true otherwise */
	}
	return (0); /* node == NULL*/
}
