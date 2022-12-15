#include "binary_trees.h"

/**
 * array_to_bst - buikds a Binary Search Tree from an array
 * @array: pointer to the first elem in an array of integers
 * @size: the number of elements in array
 * Return: pointer to the built tree's root node or NULL if function
 * fails
 */
bst_t *array_to_bst(int *array, size_t size)
{
	int i;
	bst_t *tree = NULL; /* instantiate tree */

	if (array == NULL || (int)size < 1)
		return (NULL);
	/* for every elem in array, insert node in bst */
	for (i = 0; i < (int)size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}
