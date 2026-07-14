#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * compress_line - shifts all 0's from an array to the right
 *
 * @line: Pointer to the array of integer
 * @size: Number of elements in @array
 *
 * Return : void
 */

void compress_line(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == 0)
		{
			j = i + 1;
			while (j < size)
			{
				if (line[j] == 0)
					j++;
				else
				{
					line[i] = line[j];
					line[j] = 0;
					break;
				}
			}
		}
	}
}

/**
 * reverse_line - reverses an array
 *
 * @line: Pointer to the array of integer
 * @size: Number of elements in @array
 *
 * Return : void
 */

void reverse_line(int *line, size_t size)
{
	size_t i;
	int x;

	for (i = 0; i < size / 2; i++)
	{
		x = line[i];
		line[i] = line[size - i - 1];
		line[size - i - 1] = x;
	}
}

/**
 * slide_line - reproduce the 2048 game mechanics on a single horizontal line
 *
 * @line: Pointer to the array of integer
 * @size: Number of elements in @array
 * @direction: The direction de @array should slide in
 *
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t i = 1;

	if (direction != 0 && direction != 1)
		return (0);

	if (direction == 1)
		reverse_line(line, size);

	compress_line(line, size);

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] = line[i] + line[i + 1];
			line[i + 1] = 0;
		}
	}

	compress_line(line, size);

	if (direction == 1)
		reverse_line(line, size);

	return (1);
}
