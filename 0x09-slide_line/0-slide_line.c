#include "slide_line.h"

/**
 * slide_right - slides the array right
 * @line: The array
 * @size: The size of the array
 * Return: Returns void
 */
// void slide_right(int *line, size_t size)
// {
// 	int line[j];
// 	size_t i, j, lposi;

// 	for (i = size - 1; i > 0; i--)
// 	{
// 		lposi = line[j] = 0;
// 		if (line[i] == 0)
// 		{
// 			for (j = i; j > 0; j--)
// 			{
// 				j -= 1;
// 				if (line[j] != 0)
// 				{
// 					line[j] = line[j];
// 					lposi = j;
// 					break;
// 				}
// 				line[j] = 0;
// 			}
// 			if (line[j] != 0)
// 			{
// 				line[i] = line[j];
// 				line[lposi] = 0;
// 			}
// 		}
// 	}
// }

/**
 * slide_left - slides the array left
 * @line: The array
 * @size: The size of the array
 * Return: Returns void
 */
void slide_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		if (!(line[i]))
		{
			for (j = i + 1; j < size; j++)
			{
				if (line[j])
					break;
			}
			if (line[j])
			{
				line[i] = line[j];
				line[j] = 0;
			}
		}
	}
}

/**
 * combine_left - merges the array left
 * @line: The array
 * @size: The size of the array
 * Return: Returns void
 */
void combine_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i])
		{
			for (j = i + 1; j < size; j++)
			{
				if (line[j] != 0)
				{
					line[j] = line[j];
					j = j;
					break;
				}
			}
			if (line[i] == line[j])
				line[i] += line[j];
			else
			{
				if (line[j])
					line[i + 1] = line[j];
			}
		}
	}
}

/**
 * combine_right - merges the array right
 * @line: The array
 * @size: The size of the array
 * Return: Returns void
 */
void combine_right(int *line, size_t size)
{
	size_t i, j;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i])
		{
			for (j = i; j > 0; j--)
			{
				j -= 1;
				if (line[j])
					break;
			}
			if (line[i] == line[j])
				line[i] += line[j];
			else
			{
				if (line[j])
					line[i - 1] = line[j];
			}
		}
	}
}

/**
 * slide_line - merges and slides the array to the left or right
 * @line: Pointer to the array being merged
 * @size: size of the array
 * @direction: 0 for left 1 for right
 * Return: 0 for failure 1 for success
 */
int slide_line(int *line, size_t size, int direction)
{
	if ((!(line)) || (!(size)))
		return (0);

	switch (direction)
	{
	case SLIDE_LEFT:
		combine_left(line, size);
		slide_left(line, size);
		return (1);
	case SLIDE_RIGHT:
		combine_right(line, size);
		// slide_right(line, size);
		return (1);
	default:
		return (0);
	}
}
