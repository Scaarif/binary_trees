#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of
 * another node
 * @parent: the node whose right child this node is
 * @value: this node's data value
 * Return: a pointer to the created node or NULL if parent is NULL
 * or on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right;

	/* create the new (left) node */
	right = binary_tree_node(parent, value);
	/* check that right & parent are not NULL */
	if (parent == NULL || right == NULL) /* failed */
	{
		free(right); /* this node not needed */
		return (NULL);
	}
	/* check if parent already has a right child */
	/* if so, assign it to new right's right child */
	if (parent->right != NULL)
	{
		right->right = parent->right;
		/* update / change parent's right's parent to right */
		parent->right->parent = right;
	}
	/* assign it to the parent's right */
	parent->right = right;
	return (right);
}
