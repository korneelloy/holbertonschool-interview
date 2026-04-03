#include "lists.h"
#include <stdlib.h>
/**
 * insert_node - insert node in singly linked list
 * @head: dubble pointer to head of list
 * @number: the valuie in insert
 *
 * Return: adress of new node, or NULL if failure
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
	{
		return (NULL);
	}
	new->n = number;
	listint_t *current = *head;
	listint_t *previous = NULL;

	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		return (new);
	}

	while (current != NULL)
	{
		if (number > current->n)
		{
			previous = current;
			if (current->next)
			{
				current = current->next;
			}
			else
			{
				previous->next = new;
				new->next = NULL;
				return (new);
			}
		}
		else
		{
			new->next = current;
			if (previous != NULL)
			{
				previous->next = new;
			}
			else
			{
				*head = new;
			}
			break;
		}
	}
	return (new);
}
