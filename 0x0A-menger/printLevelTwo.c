#include "menger.h"

/**
 * printLevelTwo - Prints the level 2 pattern
 * @level: level print times
 * Return: returns void
 */
void printLevelTwo(int level)
{
	int i, cubed;

	cubed = pow(3, level - 2);
	printLevelOne(level);
	for (i = 0; i < cubed; i++)
	{
		printOut();
		printSpace();
		printOut();
	}
	putchar('\n');
	for (i = 0; i < cubed; i++)
	{
		printIn();
		printSpace();
		printIn();
	}
	putchar('\n');
	for (i = 0; i < cubed; i++)
	{
		printOut();
		printSpace();
		printOut();
	}
	putchar('\n');
	printLevelOne(level);
}
