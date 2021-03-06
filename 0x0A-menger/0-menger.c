#include "menger.h"

/**
 * printCol - prints the current column
 * @size: the size of the carpet
 * @row: the row position
 * @col: the col position
 * Return: returns void
 */
void printCol(int size, int row, int col)
{
	int div, printId;

	if (col >= 0)
	{
		printId = 35;
		for (div = 1; div < size; div *= 3)
		{
			if (((row / div) % 3 == 1) && ((col / div) % 3 == 1))
				printId = 32;
		}
		putchar(printId);
		printCol(size, row, col - 1);
	}
}

/**
 * printRow - prints the current row
 * @size: the size of the carpet
 * @row: the row position
 * Return: returns void
 */
void printRow(int size, int row)
{
	if (row >= 0)
	{
		printCol(size, row, size - 1);
		putchar('\n');
		printRow(size, row - 1);
	}
}

/**
 * menger - separates non operable levels
 * @level: the input level of carpet to print
 * Return: returns void
 */
void menger(int level)
{
	int size;

	if (level == 0)
		puts("#");
	if (level > 0)
	{
		size = pow(3, level);
		printRow(size, size - 1);
	}
}
