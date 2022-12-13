#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of
 * another node
 * @parent: the node whose left child this node is
 * @value: this node's data value
 * Return: a pointer to the created node or NULL if parent is NULL
 * or on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left;

	/* create the new (left) node */
	left = binary_tree_node(parent, value);
	/* check that left & parent are not NULL */
	if (parent == NULL || left == NULL) /* failed */
	{
		free(left); /* this node not needed */
		return (NULL);
	}
	/* check if parent already has a left child */
	/* if so, assign it to new left's left */
	if (parent->left != NULL)
	{
		left->left = parent->left;
		/* update / change parent's left's parent to left */
		parent->left->parent = left;
	}
	/* assign it to the parent's left */
	parent->left = left;
	return (left);
}
