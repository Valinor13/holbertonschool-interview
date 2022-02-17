#include "menger.h"

/**
 * printSpace - prints the space layer of the current level
 *
 * Return: returns void
 */
void printSpace()
{
	printf("   ");
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
