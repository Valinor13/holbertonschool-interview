#include "sandpiles.h"

/**
 * sandpiles_sum - totals the sum of the sandpiles cell limit is 3
 * @grid1: first sandpile, in a matrix format
 * @grid2: second sandpile, in a matrix format
 * Return: returns void after printing piles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int NUMCAP = 3, LINECAP = 3, sig = 1;
	int sumnum, topplenum, i, j;

	for (i = 0; i < LINECAP; i++)
	{
		for (j = 0; j < LINECAP; j++)
		{
			sumnum = grid1[i][j] + grid2[i][j];
			grid1[i][j] = sumnum;
		}
	}
	while (sig != 0)
	{
		sig = 1;
		for (i = 0; i < LINECAP; i++)
		{
			for (j = 0; j < LINECAP; j++)
			{
				if (grid1[i][j] > NUMCAP)
				{
					topplenum = grid1[i][j];
					sig = 2;
					break;
				}
			}
			if (sig == 2)
				break;
		}
		if (sig == 2)
		{
			print grid1
			topple grid with topplenum
		}
		else
			sig = 0;
	}
}
