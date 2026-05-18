#ifndef SANDPILES_H
#define SANDPILES_H

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

/**
 * checkgrid - Checks if grid is stable, topples it if not
 * @grid1: 3x3 grid
 */
void checkgrid(int grid1[3][3]);

/**
 * topplegrid - Topples all unstable cells simultaneously
 * @grid1: 3x3 grid
 */
void topplegrid(int grid1[3][3]);

#endif /* SANDPILES_H */
