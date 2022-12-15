#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 * Return: pointer to the sibling if existent and NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent, *sib;

	/* get node's defined & has a parent */
	if (node == NULL || node->parent == NULL)
		return (NULL);
	/* return parent's other child (could be NULL or a value) */
	parent = node->parent;
	if (parent->left == node)
		sib = parent->right;
	else
		sib = parent->left;
	return (sib);
}
