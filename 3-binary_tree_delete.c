#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
	/* delete all nodes to the left */
		binary_tree_delete(tree->left);
	/* delete all nodes to the right */
		binary_tree_delete(tree->right);
	/* delete the root node */
		free(tree);
	}
}
