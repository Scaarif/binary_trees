#include "binary_trees.h"


/**
 * binary_tree_node - creates a binary tree node
 * @parent: a pointer to this node's parent
 * @value: this node's data value
 * Return: a pointer to the new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	/* allocate memory to the new node */
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL); /* malloc failed */
	/* assign data & link to node to the parent */
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
