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
	if (level > 0)
	{
		printOut();
		putchar('\n');
		printIn();
		putchar('\n');
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
