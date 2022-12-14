#include "binary_trees.h"

/**
 * leaves - counts the number of leaves in a tree
 * @tree: pointer to the tree whose leaves to count
 * Return: the count
 */
size_t leaves(const binary_tree_t *tree)
{
	size_t left, right;

	/* base case: if node is childless, it's a leaf */
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/* get the number of nodes in left sub-tree */
	left = leaves(tree->left);
	/* get the number of nodes in right sub-tree */
	right = leaves(tree->right);
	/* return the sum  */
	return (left + right);
}

/**
 * binary_tree_leaves - counts the number of leaves in a binary tree
 * NOTE: i.e. the number of childless nodes
 * @tree: pointer to the tree's root node
 * Return: the count
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	return (leaves(tree));
}
