#include "menger.h"
/**
 * printIn - prints the middle layer of the current level
 *
 * Return: returns void
 */
void printIn()
{
	printf("# #");
}

/**
 * printOut - prints the top/bottom layer of the current level
 *
 * Return: returns void
 */
void printOut()
{
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
			printOut();
		putchar('\n');
		for (i = 0; i < level; i++)
			printIn();
		putchar('\n');
		for (i = 0; i < level; i++)
			printOut();
		putchar('\n');
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
