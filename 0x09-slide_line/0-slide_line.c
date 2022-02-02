#include "slide_line.h"

/**
 * slide_right - slides the array right
 * @line: The array
 * @size: The size of the array
 * Return: Returns void
 */
void slide_right(int *line, size_t size)
{
	int mid;
	size_t i, j, lposi;

	for (i = size - 1; i > 0; i--)
	{
		lposi = mid = 0;
		if (line[i] == 0)
		{
			for (j = i; j > 0; j--)
			{
				j -= 1;
				if (line[j] != 0)
				{
					mid = line[j];
					lposi = j;
					break;
				}
				mid = 0;
			}
			if (mid != 0)
			{
				line[i] = mid;
				line[lposi] = 0;
			}
		}
	}
}

/**
 * slide_left - slides the array left
 * @line: The array
 * @size: The size of the array
 * Return: Returns void
 */
void slide_left(int *line, size_t size)
{
	int mid;
	size_t i, j, rposi;

	for (i = 0; i < size - 1; i++)
	{
		rposi = mid = 0;
		if (line[i] == 0)
		{
			for (j = i + 1; j < size; j++)
			{
				if (line[j] != 0)
				{
					mid = line[j];
					rposi = j;
					break;
				}
			}
			if (mid != 0)
			{
				line[i] = mid;
				line[rposi] = 0;
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
	int mid, left;
	size_t i, j, rposi;

	for (i = 0; i < size - 1; i++)
	{
		rposi = left = mid = 0;
		if (line[i] != 0)
		{
			left = line[i];
			for (j = i + 1; j < size; j++)
			{
				if (line[j] != 0)
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
		lposi = right = mid = 0;
		if (line[i] != 0)
		{
			right = line[i];
			for (j = i; j > 0; j--)
			{
				j -= 1;
				if (line[j] != 0)
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
		slide_right(line, size);
		return (1);
	default:
		return (0);
	}
}
