#include "sandpiles.h"

/**
 * sandpiles_sum - totals the sum of the sandpiles cell limit is 3
 * @grid1: first sandpile, in a matrix format
 * @grid2: second sandpile, in a matrix format
 * Return: returns void after printing piles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int sumnum, i, j;

	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			sumnum = grid1[i][j] + grid2[i][j];
			grid1[i][j] = sumnum;
		}
	}
}
