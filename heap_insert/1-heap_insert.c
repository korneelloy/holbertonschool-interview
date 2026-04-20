#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

/**
 * count_nodes - counts nodes in a binary tree
 * @tree: pointer to root
 *
 * Return: number of nodes
 */
size_t count_nodes(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * create_node - allocates and initializes a heap node
 * @value: value to store
 *
 * Return: pointer to new node, or NULL on failure
 */
heap_t *create_node(int value)
{
	heap_t *node;

	node = malloc(sizeof(heap_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return (node);
}

/**
 * get_index - finds the index in its level and the level size
 * @position: position of the next node
 * @level_size: pointer to store the level size
 *
 * Return: index within the level
 */
int get_index(int position, int *level_size)
{
	*level_size = 1;
	while ((*level_size) * 2 <= position)
		*level_size *= 2;
	return (position - *level_size);
}

/**
 * bubble_up - swaps values up to maintain max-heap property
 * @node: pointer to the newly inserted node
 *
 * Return: pointer to node where the value ended up
 */
heap_t *bubble_up(heap_t *node)
{
	int temp_val;

	while (node->parent && node->n > node->parent->n)
	{
		temp_val = node->n;
		node->n = node->parent->n;
		node->parent->n = temp_val;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node
 *
 * Return: pointer to new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *current;
	int position, level_size, index;

	if (!root)
		return (NULL);
	node = create_node(value);
	if (!node)
		return (NULL);
	if (!*root)
	{
		*root = node;
		return (node);
	}
	position = count_nodes(*root) + 1;
	index = get_index(position, &level_size);
	current = *root;
	level_size /= 2;
	while (level_size > 1)
	{
		if (index < level_size)
			current = current->left;
		else
		{
			current = current->right;
			index -= level_size;
		}
		level_size /= 2;
	}
	node->parent = current;
	if (index == 0)
		current->left = node;
	else
		current->right = node;
	return (bubble_up(node));
}
