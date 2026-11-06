#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_size - counts the nodes of a binary tree
 * @tree: pointer to the root node
 *
 * Return: number of nodes
 */
static size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_last_node - finds the last level-order node of a complete tree
 * @root: pointer to the root node
 * @size: number of nodes in the tree
 *
 * Return: pointer to the last node
 */
static heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t bit = 1;

	while ((bit << 1) <= size)
		bit <<= 1;
	for (bit >>= 1; bit; bit >>= 1)
		root = (size & bit) ? root->right : root->left;
	return (root);
}

/**
 * sift_down - restores the max heap property from the given node
 * @node: pointer to the node to sift down
 */
static void sift_down(heap_t *node)
{
	heap_t *max;
	int tmp;

	while (node)
	{
		max = node;
		if (node->left && node->left->n > max->n)
			max = node->left;
		if (node->right && node->right->n > max->n)
			max = node->right;
		if (max == node)
			break;
		tmp = node->n;
		node->n = max->n;
		max->n = tmp;
		node = max;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int value;

	if (!root || !*root)
		return (0);
	value = (*root)->n;
	last = get_last_node(*root, tree_size(*root));
	if (last == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;
	(*root)->n = last->n;
	free(last);
	sift_down(*root);
	return (value);
}
