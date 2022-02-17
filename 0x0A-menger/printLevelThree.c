#include "menger.h"

/** printLevelThreeHelperIn - reduce lines of code in print function
 * Return: returns void
 */
void printLevelThreeHelperIn()
{
	int j;

	printOut();
	printSpace();
	printOut();
	for (j = 0; j < 3; j++)
		printSpace();
	printOut();
	printSpace();
	printOut();
}

/** printLevelThreeHelperOut - reduce lines of code in print function
 * Return: returns void
 */
void printLevelThreeHelperOut()
{
	int j;

	for (j = 0; j < 3; j++)
		printOut();
	for (j = 0; j < 3; j++)
		printSpace();
	for (j = 0; j < 3; j++)
		printOut();
}

/**
 * printLevelThreeOut - prints level 3
 * @level: print levels
 * Return: returns void
 */
void printLevelThreeOut(int level)
{
	int i, j, cubed;

	cubed = pow(3, level - 3);
	for (i = 0; i < cubed; i++)
		printLevelThreeHelperOut();
	putchar('\n');
	for (i = 0; i < cubed; i++)
	{
		for (j = 0; j < 3; j++)
			printIn();
		for (j = 0; j < 3; j++)
			printSpace();
		for (j = 0; j < 3; j++)
			printIn();
	}
	putchar('\n');
	for (i = 0; i < cubed; i++)
		printLevelThreeHelperOut();
	putchar('\n');
}

/**
 * printLevelThreeIn - prints level 3
 * @level: print levels
 * Return: returns void
 */
void printLevelThreeIn(int level)
{
	int i, j, cubed;

	cubed = pow(3, level - 3);
	for (i = 0; i < cubed; i++)
		printLevelThreeHelperIn();
	putchar('\n');
	for (i = 0; i < cubed; i++)
	{
		printIn();
		printSpace();
		printIn();
		for (j = 0; j < 3; j++)
			printSpace();
		printIn();
		printSpace();
		printIn();
	}
	putchar('\n');
	for (i = 0; i < cubed; i++)
		printLevelThreeHelperIn();
	putchar('\n');
}

/**
 * printLevelThree - Prints the level 3 pattern
 * @level: level print times
 * Return: returns void
 */
void printLevelThree(int level)
{
	printLevelTwo(level);
	printLevelThreeOut(level);
	printLevelThreeIn(level);
	printLevelThreeOut(level);
	printLevelTwo(level);
}
