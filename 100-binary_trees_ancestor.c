#include "binary_trees.h"

/**
 * get_depth - measures the depth of a tree node
 * @tree: the node whose depth to measure
 * Return: the measured depth
 */
size_t get_depth(const binary_tree_t *tree)
{
	size_t  depth;

	if (tree == NULL)
		return (0);
	/* work backwards towards root */
	depth = get_depth(tree->parent);
	return (depth + 1);
}


/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * NOTE: i.e. the lowest/closest common ancestor to the nodes
 * (could be one of the nodes)
 * @first: pointer to the first node whose common ancestor to find
 * @second: pointer to the second node whose common ancestor to find
 * Return: pointer to the ancestor & NULL otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int height_diff, i;

	/* if either of the  nodes is NULL, return NULL */
	if (!first || !second)
		return (NULL);
	height_diff = (int)(get_depth(first) - get_depth(second));
	if (height_diff < 0) /* second is deeper than first */
	{
		/* trace back second's ancestors up until first's depth */
		for (i = 0; i > height_diff && second; i--)
		{
			second = second->parent;
		}
	}
	else if (height_diff > 0) /* first is deeper than second */
	{
		/* trace back first's ancestors up until second's depth */
		for (i = 0; i < height_diff && first; i++)
		{
			first = first->parent;
		}
	}
	/* check if one node is an ancestor of the other */
	if (first == second)
		return ((binary_tree_t *)first);
	/* else, at the same level - trace back both, comparing parents */
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first); /* which's both node'sancestor */
}
