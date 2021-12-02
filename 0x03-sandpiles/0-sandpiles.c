#include "sandpiles.h"

/**
 * print_pile - Print 3x3 grid
 * @grid: 3x3 grid
 * Return: returns void
 */
static void print_pile(int grid[3][3])
{
	int i, j;

	printf("=\n");
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
 * combine_piles - Adds 2 sandpiles together
 * @one: the base pile
 * @two: the pile being added
 * Return: returns void
 */
void combine_piles(int one[3][3], int two[3][3])
{
	int sumnum, i, j;
	int LINECAP = 3;

	for (i = 0; i < LINECAP; i++)
	{
		for (j = 0; j < LINECAP; j++)
		{
			sumnum = one[i][j] + two[i][j];
			one[i][j] = sumnum;
		}
	}
}

/**
 * check_oil - checks if sands need toppled
 * @one: sandpile
 * @sig: signal pointer
 * Return: returns void
 */
void check_oil(int one[3][3], int *sig)
{
	int i, j, LINECAP = 3, NUMCAP = 3;

	for (i = 0; i < LINECAP; i++)
	{
		for (j = 0; j < LINECAP; j++)
		{
			if (one[i][j] > NUMCAP)
			{
				*sig = 2;
				break;
			}
		}
		if (*sig == 2)
			break;
	}
}

/**
 * topple_sands - topple sand cells equal to topple number
 * @sandpile: the grid of sand cells
 * @burnpile: a static copy of sandpile pre-topple
 * Return: returns void
 */
void topple_sands(int sandpile[3][3], int burnpile[3][3])
{
	int i, j, LINECAP = 3;

	for (i = 0; i < LINECAP; i++)
	{
		for (j = 0; j < LINECAP; j++)
		{
			burnpile[i][j] = sandpile[i][j];
		}
	}
	for (i = 0; i < LINECAP; i++)
	{
		for (j = 0; j < LINECAP; j++)
		{
			if ((sandpile[i][j] > 3) && (burnpile[i][j] > 3))
			{
				sandpile[i][j] -= 4;
				if (i > 0)
					sandpile[i - 1][j] += 1;
				if (i < 2)
					sandpile[i + 1][j] += 1;
				if (j > 0)
					sandpile[i][j - 1] += 1;
				if (j < 2)
					sandpile[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - totals the sum of the sandpiles cell limit is 3
 * @grid1: first sandpile, in a matrix format
 * @grid2: second sandpile, in a matrix format
 * Return: returns void after printing piles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int sig = 1;
	int *sigp;

	sigp = &sig;
	combine_piles(grid1, grid2);
	while (sig != 0)
	{
		sig = 1;
		check_oil(grid1, sigp);
		if (sig == 2)
		{
			print_pile(grid1);
			topple_sands(grid1, grid2);
		}
		else
			sig = 0;
	}
}
