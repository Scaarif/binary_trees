#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * NOTE: i.e. the node's parent's sibling
 * @node: a pointer to the node to find the uncle
 * Return: pointer to the uncle if existent and NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *g_parent, *uncle;

	/* get node's defined & has a parent */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	/* return node's parent's parent's other child (could be NULL or a value) */
	g_parent = node->parent->parent;
	if (g_parent->left == node->parent)
		uncle = g_parent->right;
	else
		uncle = g_parent->left;
	return (uncle);
}
