#include "menger.h"

/**
 * printTop - prints the top layer of the current level
 * @layer: current layer of level
 * Return: returns void
 */
void printTop(int layer)
{
	int i, cubed;

	cubed = pow(3, layer);

	for (i = 0; i < cubed; i++)
		printf("###");
}

/**
 * printLevel - recursive function to print each level of carpet
 * @level: the number of levels to print
 * Return: returns void
 */
void printLevel(int level)
{
	int i;

	if (level > 0)
	{
		for (i = 0; i < level; i++)
		{
			printTop(i);
		}
		putchar("\n");
		printLevel(level - 1);
	}
}

/**
 * menger - separates non operable levels
 * @level: the input level of carpet to print
 * Return: returns void
 */
void menger(int level)
{
	if (level == 0)
		puts("#");
	if (level > 0)
	{
		printLevel(level);
	}
}
