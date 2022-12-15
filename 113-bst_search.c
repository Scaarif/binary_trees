#include "binary_trees.h"

/**
 * bst_search - searches for a value in a binary search tree
 * @tree: pointer to the root node of the tree
 * @value: the value whose containing node to search for
 * Return: pointer to the value containing node and NULL if not found
 * or if tree is NULL
 */
bst_t *bst_search(bst_t *tree, int value)
{
	bst_t *curr, *parent;

	/* empty tree - make new node the root */
	if (tree)
	{
		curr = tree;
		while (curr) /* while we still have a node */
		{
			parent = curr;
			if (value == parent->n)
				return (parent);
			else if (value < parent->n) /* search left sub-tree*/
			{
				curr = curr->left;
				if (curr && curr->n == value)
					return (curr);
			}
			else /* search right sub-tree */
			{
				curr = curr->right;
				if (curr && curr->n == value)
					return (curr);
			}
		}
		return (NULL); /* end of tree, value not found */
	}
	return (NULL); /* tree == NULL */
}
