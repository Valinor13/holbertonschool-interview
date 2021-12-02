#include "sandpiles.h"

/**
 * print_pile - Print 3x3 grid
 * @grid: 3x3 grid
 *
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
 * Return: returns the base pile
 */
void combine_piles(int one[3][3], int two[3][3])
{
	int LINECAP = 3, sumnum, i, j;

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
 * sandpiles_sum - totals the sum of the sandpiles cell limit is 3
 * @grid1: first sandpile, in a matrix format
 * @grid2: second sandpile, in a matrix format
 * Return: returns void after printing piles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int NUMCAP = 3, LINECAP = 3, sig = 1;
	int topplenum, i, j;

	combine_piles(grid1, grid2);
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
			print_pile(grid1);
			sig = 0;
		}
		else
		{
			sig = 0;
			printf("%d", topplenum);
		}
	}
}
