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
 * grab_topplenum - gets the topplenum for the piles
 * @one: the sandpile
 * @sig: the signal pointer for the topple loop
 * @tpn: the topple number in pointer
 * Return: returns void
 */
void grab_topplenum(int one[3][3], int *sig, int *tpn)
{
	int i, j;

	for (i = 0; i < LINECAP; i++)
		{
			for (j = 0; j < LINECAP; j++)
			{
				if (one[i][j] > NUMCAP)
				{
					*tpn = one[i][j];
					*sig = 2;
					break;
				}
			}
			if (*sig == 2)
				break;
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
	int topplenum = 0, sig = 1;
	int *tpn, *sigp;

	tpn = &topplenum;
	sigp = &sig;
	combine_piles(grid1, grid2);
	while (sig != 0)
	{
		sig = 1;
		grab_topplenum(grid1, sigp, tpn);
		if (sig == 2)
		{
			print_pile(grid1);
			sig = 0;
		}
		else
		{
			sig = 0;
			printf("%d\n", topplenum);
		}
	}
}
