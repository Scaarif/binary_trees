#include "binary_trees.h"

/**
 * leaves - counts the number of leaves in a tree
 * @tree: pointer to the tree whose leaves to count
 * Return: the count
 */
size_t leaves(const binary_tree_t *tree)
{
	size_t left, right;

	/* base case: if node has at least 1 child, it's a non_leaf */
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
 * size - returns the size of tree (number of nodes in it)
 * @tree: pointer to the tree's root node
 * Return: the size
 */
size_t size(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = size(tree->left);
	right = size(tree->right);
	return (left + 1 + right);
}

/**
 * binary_tree_nodes - counts the number of non_leaf nodes in a binary tree
 * NOTE: i.e. the number of nodes with at least 1 child
 * @tree: pointer to the tree's root node
 * Return: the count
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size_, leaves_;

	/* get the size of tree (start node excluded) */
	size_ = size(tree);
	/* get the number of leaves in tree */
	leaves_ = leaves(tree);
	/* get the number of non_leaves */
	return (size_ - leaves_);
}
