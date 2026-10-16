#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - moves an element down the heap until it is in place
 * @array: the array to sort
 * @heap_size: number of elements currently in the heap
 * @index: index of the element to move down
 * @size: total size of the array (used for printing)
 */
void sift_down(int *array, int heap_size, int index, size_t size)
{
	int current = index;
	int potential_mover, index_bigest, bigest;

	while (2 * current + 1 < heap_size)
	{
		potential_mover = array[current];
		index_bigest = 2 * current + 1;
		bigest = array[index_bigest];
		if (2 * current + 2 < heap_size &&
		    bigest < array[2 * current + 2])
		{
			index_bigest = 2 * current + 2;
			bigest = array[index_bigest];
		}
		if (potential_mover < bigest)
		{
			array[index_bigest] = potential_mover;
			array[current] = bigest;
			print_array(array, size);
			current = index_bigest;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: the array to sort
 * @size: number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (array == NULL || size < 2)
		return;

	/* Phase 1: build the max heap */
	for (i = (int)size / 2 - 1; i >= 0; i--)
		sift_down(array, (int)size, i, size);

	/* Phase 2: move the max to the end, shrink the heap, repair it */
	for (i = (int)size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}
