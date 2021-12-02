#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
	for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * combine_grids - takes 2 matrices and sums them into 1
 * @one: matrix 1
 * @two: matrix 2
 * Return: one altered to 3
 */
int **combine_grids(int one[3][3], int two[3][3])
{
	int sumnum;

	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			sumnum = one[i][j] + two[i][j];
			one[i][j] = sumnum;
		}
	}
	return (one);
}

/**
 * sandpiles_sum - totals the sum of the sandpiles cell limit is 3
 * @grid1: first sandpile, in a matrix format
 * @grid2: second sandpile, in a matrix format
 * Return: returns void after printing piles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid3 = combine_grids(grid1, grid2);
}
