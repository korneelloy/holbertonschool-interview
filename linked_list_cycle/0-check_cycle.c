#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: linked list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t **visited = malloc(sizeof(listint_t *));
	int size = 0;
	int i;

	while (list != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (list == visited[i])
			{
				free(visited);
				return (1);
			}
		}
		visited = realloc(visited, sizeof(listint_t *) * (size + 1));
		if (visited == NULL)
			return (0);
		visited[size] = list;
		size++;
		list = list->next;
	}
	free(visited);
	return (0);
}
