#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - prints the (sub)array being searched
 * @array: pointer to the first element
 * @size: number of elements
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		printf("%d%s", array[i], i + 1 < size ? ", " : "\n");
}

/**
 * search_rec - recursively searches for the first occurrence of value
 * @array: pointer to the first element of the (sub)array
 * @size: number of elements in the (sub)array
 * @value: value to search for
 *
 * Return: index of value relative to @array, or -1 if not found
 */
int search_rec(int *array, size_t size, int value)
{
	size_t mid;
	int idx;

	if (size == 0)
		return (-1);

	print_array(array, size);
	mid = (size - 1) / 2;

	if (array[mid] == value && (mid == 0 || array[mid - 1] != value))
		return ((int)mid);

	if (array[mid] == value)
		return (search_rec(array, mid + 1, value));

	if (array[mid] > value)
		return (search_rec(array, mid, value));

	idx = search_rec(array + mid + 1, size - mid - 1, value);
	if (idx == -1)
		return (-1);
	return ((int)mid + 1 + idx);
}

/**
 * advanced_binary - searches for the first index of a value in a sorted array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (search_rec(array, size, value));
}
