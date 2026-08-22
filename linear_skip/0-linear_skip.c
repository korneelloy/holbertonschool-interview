#include <stdio.h>
#include <stdlib.h>

#include "search.h"

/**
 * linear_skip - search in skiplist
 *
 * @list: Pointer to the head of the list
 * @value: the value we are lookign fro
 *
 * Return: node or null if not found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current_node;
	skiplist_t *prev_express;
	int current_value;

	if (list == NULL)
		return (NULL);

	current_node = list;
	prev_express = list;
	current_value = list->n;

	while (current_value < value && current_node->express != NULL)
	{
		prev_express = current_node;
		current_node = current_node->express;
		current_value = current_node->n;
		printf("Value checked at index [%lu] = [%d]\n",
		       current_node->index, current_value);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev_express->index, current_node->index);

	if (current_value > value)
		current_node = prev_express;

	while (current_node != NULL && current_node->n < value)
	{
		if (current_node != NULL)
			printf("Value checked at index [%lu] = [%d]\n",
			       current_node->index, current_node->n);
		current_node = current_node->next;
	}

	if (current_node != NULL && current_node->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current_node->index, current_node->n);
		return (current_node);
	}

	return (NULL);
}
