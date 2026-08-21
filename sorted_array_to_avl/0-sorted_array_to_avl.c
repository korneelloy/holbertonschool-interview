#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

static avl_t *recursion(int *array, size_t size, avl_t *parent);

/**
 * sorted_array_to_avl - change sorted array to AVL
 *
 * @array: Pointer to the array to be converted
 * @size: Number of elements in @array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (recursion(array, size, NULL));
}

/**
 * recursion - recursively builds a balanced AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array segment
 * @size: Number of elements in this segment
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the created node, or NULL
 */
static avl_t *recursion(int *array, size_t size, avl_t *parent)
{
	avl_t *node;
	size_t mid;

	if (size == 0)
		return (NULL);

	mid = (size - 1) / 2;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;
	node->left = recursion(array, mid, node);
	node->right = recursion(array + mid + 1, size - mid - 1, node);

	return (node);
}
