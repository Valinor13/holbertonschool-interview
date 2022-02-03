#include "slide_line.h"

/**
 * slide_right - slides the array right
 * @line: The array
 * @size: The size of the array
 * Return: Returns void
 */
/*void slide_right(int *line, size_t size)
{
	int mid;
	size_t i, j, left;

	for (i = size - 1; i > 0; i--)
	{
		mid = 0;
		if (!(line[i]))
		{
			for (j = i; j > 0; j--)
			{
				j -= 1;
				if (line[j])
				{
					mid = line[j];
					left = j;
					break;
				}
			}
			if (mid)
			{
				line[i] = mid;
				line[left] = 0;
			}
		}
	}
}
*/
/**
 * slide_left - slides the array left
 * @line: The array
 * @size: The size of the array
 * Return: Returns void
 */
void slide_left(int *line, size_t size)
{
	int mid;
	size_t i, j, right;

	for (i = 0; i < size - 1; i++)
	{
		mid = 0;
		if (!(line[i]))
		{
			for (j = i + 1; j < size; j++)
			{
				if (line[j])
				{
					mid = line[j];
					right = j;
					break;
				}
			}
			if (mid)
			{
				line[i] = mid;
				line[right] = 0;
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
	int tmp, left, mid;
	size_t i, j, right, l;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i])
		{
			left = line[i];
			l = i;
			for (j = i + 1; j < size; j++)
			{
				if (line[j])
				{
					mid = line[j];
					right = j;
					break;
				}
			}
			if (left == mid)
			{
				left += mid;
				line[i] = left;
				line[right] = 0;
			}
			if (line[right])
			{
				tmp = line[right];
				line[right] = 0;
				line[l + 1] = tmp;
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
	int right, mid, tmp;
	size_t i, j;

	for (i = size - 1; i > 0; i--)
	{
/*		printf("i:%lu\n", i);
		printf("line[i]:%d\n", line[i]);
*/		if (line[i])
		{
			right = line[i];
			for (j = i; j > 0; j--)
			{
				if (line[j - 1])
				{
					mid = line[j - 1];
					break;
				}
			}
			printf("right:%d mid:%d\n", right, mid);
			if (right == mid)
			{
				printf("line[i]:%d line[j]:%d\n", line[i], line[j]);
				right += mid;
				line[i] = right;
				line[j] = 0;
				printf("line[i]:%d line[j]:%d\n", line[i], line[j]);
			}
			else if (line[j])
			{
				if (j != (i - 1))
				{
					tmp = line[j];
					line[j] = 0;
					line[i - 1] = tmp;
				}
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
		/*		slide_right(line, size);
		 */
		return (1);
	default:
		return (0);
	}
}
