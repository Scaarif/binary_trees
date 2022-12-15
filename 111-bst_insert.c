#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a binary search tree
 * @tree: double pointer to the root node of the tree
 * @value: the value to be stored in the inserted node
 * Return: pointer to the inserted node and NULL if failure or
 * if node already exists (i.e. a node with value already in tree)
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;
	bst_t *curr, *parent;

	/* empty tree - make new node the root */
	if (*tree == NULL)
	{
		new = binary_tree_node(*tree, value);
		*tree = new;
		return (new);
	}
	else
	{
		curr = *tree;
		while (1)
		{
			parent = curr;
			if (value == parent->n)
				return (NULL);
			else if (value < parent->n) /* into left sub-tree*/
			{
				curr = curr->left;
				if (curr == NULL)
				{
					new = binary_tree_node(parent, value);
					parent->left = new;
					return (new);
				}
			}
			else /* into right sub-tree */
			{
				curr = curr->right;
				if (curr == NULL)
				{
					new = binary_tree_node(parent, value);
					parent->right = new;
					return (new);
				}
			}
		}
	}
}
