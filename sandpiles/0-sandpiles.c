#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid1: 3x3 grid
 *
 */
static void print_grid(int grid1[3][3])
{
	printf("%c", '=');
	printf("\n");
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}

/**
 * checkgrid - chekcs if grid unstable
 * if yes, prints grid and topples it
 * @grid1: 3x3 grid
 *
 */
void checkgrid(int grid1[3][3])
{
	int i, j, unstable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				unstable = 1;
			}
		}
	}
	if (unstable)
	{
		print_grid(grid1);
		topplegrid(grid1);
	}
}

/**
 * topplegrid - topples grid
 * @grid1: 3x3 grid
 *
 */
void topplegrid(int grid1[3][3])
{

	int i, j, x;
	int griddelta[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			griddelta[i][j] = 0;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				griddelta[i][j] -= 4;
				x = i - 1;
				if (x >= 0)
					griddelta[x][j] += 1;
				x = i + 1;
				if (x < 3)
					griddelta[x][j] += 1;
				x = j - 1;
				if (x >= 0)
					griddelta[i][x] += 1;
				x = j + 1;
				if (x < 3)
					griddelta[i][x] += 1;
			}
		}
	}
	sandpiles_sum(grid1, griddelta);
}

/**
 * sandpiles_sum - sums 2 sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}

	checkgrid(grid1);
}
