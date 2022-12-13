#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root node
 * NOTE: the root node has no parent, NULL
 * @node: pointer to the node to check
 * Return: 1 if node is root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL)
	{
		/* check that it has no parent */
		if (node->parent != NULL)
			return (0);
		return (1); /* true otherwise */
	}
	return (0); /* node == NULL*/
}
