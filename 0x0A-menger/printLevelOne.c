#include "menger.h"

/**
 * printLevelOne - Prints the level 1 pattern n times
 * @level: level print times
 * Return: returns void
 */
void printLevelOne(int level)
{
	int i, cubed;

	cubed = pow(3, level - 1);
	for (i = 0; i < cubed; i++)
		printOut();
	putchar('\n');
	for (i = 0; i < cubed; i++)
		printIn();
	putchar('\n');
	for (i = 0; i < cubed; i++)
		printOut();
	putchar('\n');
}
