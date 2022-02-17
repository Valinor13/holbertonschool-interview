#include "menger.h"

/**
 * printSpace - prints the space layer of the current level
 *
 * Return: returns void
 */
void printSpace()
{
	printf("  ");
}

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
 * printLevelOne - Prints the level 1 pattern n times
 * Return: returns void
 */
void printLevelOne(int cubed)
{
	int i;

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

/**
 * printLevelTwo - Prints the level 2 pattern
 * @cubed: level print times
 * Return: returns void
 */
void printLevelTwo(int cubed)
{
	int i;

	printLevelOne(cubed);
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
	printLevelOne(cubed);
}

/**
 * menger - separates non operable levels
 * @level: the input level of carpet to print
 * Return: returns void
 */
void menger(int level)
{
	int cubed;

	cubed = pow(3, level - 1);
	switch (level)
	{
	case 0:
		puts("#");
		break;
	case 1:
		printLevelOne(cubed);
		break;
	case 2:
		printLevelTwo(cubed);
		break;
	}
}
