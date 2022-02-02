#include "slide_line.h"

/**
 * combine_left - merges the array left
 * @line: The array
 * @size: The size of the array
 * Return: Returns void
 */
void combine_left(int *line, size_t size)
{
	int mid, left;
	size_t i, j, rposi;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i])
		{
			left = line[i];
			for (j = i + 1; j < size; j++)
			{
				if (line[j])
				{
					mid = line[j];
					rposi = j;
					break;
				}
			}
			if (left == mid)
			{
				line[i] = left + mid;
				line[rposi] = 0;
			}
			else
			{
				line[rposi] = 0;
				line[i + 1] = mid;
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
	int mid, right;
	size_t i, j, lposi;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i])
		{
			right = line[i];
			for (j = i; j > 0; j--)
			{
				if (j - 1 >= 1)
					j -= 1;
				if (line[j])
				{
					mid = line[j];
					lposi = j;
					break;
				}
			}
			if (right == mid)
			{
				line[i] = right + mid;
				line[lposi] = 0;
			}
			else
			{
				line[lposi] = 0;
				line[i - 1] = mid;
			}
		}
	}
}

/**
 * slide_line - merges the array to the left or right
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
		return (1);
	case SLIDE_RIGHT:
		combine_right(line, size);
		return (1);
	default:
		return (0);
	}
}
