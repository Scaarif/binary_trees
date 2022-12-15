#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - does the actual checking
 * @tree: pointer to the root node
 * @min: the minimum value in tree
 * @max: the maximum value in tree
 * Return: 1 if true and 0 otherwise
 */
int is_bst(binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1); /* end of subtree, bst */
	return (tree->n > min && tree->n < max &&
			is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a Binary Search Tree
 * NOTE: all data on the left subtree < root->data and all
 * data on the right subtree > root->data
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if true and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min = INT_MIN, max = INT_MAX;

	if (tree == NULL)
		return (0);
	return (is_bst((binary_tree_t *)tree, min, max));
}
