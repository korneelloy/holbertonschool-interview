#include <stdio.h>
#include <stdlib.h>

#include "search.h"

/**
 * print_checked - print function
 *
 * @index: index
 * @value: value
 *
 * Return: void
 */

void print_checked(long index, int value)
{
	printf("Value checked at index [%lu] = [%d]\n", index, value);
}

/**
 * print_found - print function
 *
 * @index: index
 * @index_two: index
 *
 * Return: void
 */

void print_found(long index, long index_two)
{
	printf("Value found between indexes [%lu] and [%lu]\n", index, index_two);
}

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
	skiplist_t *current_node, *prev_express, *tail;
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
		print_checked(current_node->index, current_value);
	}
	if (current_value >= value)
	{
		print_found(prev_express->index, current_node->index);
		current_node = prev_express;
	}
	else
	{
		tail = current_node;
		while (tail->next != NULL)
			tail = tail->next;
		print_found(current_node->index, tail->index);
	}
	while (current_node != NULL && current_node->n < value)
	{
		if (current_node != NULL)
			print_checked(current_node->index, current_node->n);
		current_node = current_node->next;
	}
	if (current_node != NULL && current_node->n == value)
	{
		print_checked(current_node->index, current_node->n);
		return (current_node);
	}
	return (NULL);
}
