#include <stdlib.h>
#include <stdio.h>

#include <math.h>

#include "menger.h"

/**
 * est_vide - checks if print in Menger Sponge should be empty
 *
 * @x: level in Menger Sponge
 * @y: position in Menger Sponge
 *
 * Return: 1 if empty, otherwise 0
 */

int est_vide(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if ((x % 3 == 1) && (y % 3 == 1))
		{
			return (1);
		}
		x /= 3;
		y /= 3;
	}
	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
 *
 * Return : void
 */

void menger(int level)
{
	if (level < 0)
		return;

	int size = pow(3, level);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if (est_vide(i, j))
			{
				printf("%s", " ");
			}
			else
			{
				printf("%s", "#");
			}
		printf("\n");
	}
}
