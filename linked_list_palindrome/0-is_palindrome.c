#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * list_length - returns the number of nodes in a linked list
 * @list: pointer to the head of the list
 * Return: number of nodes
 */
static int list_length(listint_t *list)
{
  int i = 0;

  while (list)
  {
    i++;
    list = list->next;
  }
  return (i);
}

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the list to reverse
 * Return: pointer to the new head (former tail)
 */
static listint_t *reverse_list(listint_t *head)
{
  listint_t *prev = NULL;
  listint_t *current = head;
  listint_t *next;

  while (current)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
  listint_t *left, *right, *mid;
  int len, i, result = 1;

  if (!head || !*head || !(*head)->next)
    return (1);

  len = list_length(*head);

  /* advance mid to start of second half */
  mid = *head;
  for (i = 0; i < (len + 1) / 2; i++)
    mid = mid->next;

  /* reverse second half */
  right = reverse_list(mid);

  /* compare left half and reversed right half */
  left = *head;
  mid = right;
  while (mid)
  {
    if (left->n != mid->n)
    {
      result = 0;
      break;
    }
    left = left->next;
    mid = mid->next;
  }

  return (result);
}
