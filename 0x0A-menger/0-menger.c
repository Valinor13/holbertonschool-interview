#include "menger.h"

/**
 * menger - separates non operable levels
 * @level: the input level of carpet to print
 * Return: returns void
 */
void menger(int level)
{
	switch (level)
	{
	case 0:
		puts("#");
		break;
	case 1:
		printLevelOne(level);
		break;
	case 2:
		printLevelTwo(level);
		break;
	case 3:
		printLevelThree(level);
		break;
	case 4:
		printLevelFour(level);
		break;
	}
}
