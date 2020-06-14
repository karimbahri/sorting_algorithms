#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * swap - swap the values of two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sort a list
 * @array: array of integers
 * @size: size of ze array
 */

void shell_sort(int *array, size_t size)
{
	int i;
	size_t j;
	size_t gap = 1;



	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (gap = gap; gap > 0; gap = (gap -1) / 3)
	{
		print_array(array, size);
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] > array[i])
					break;

				swap(&array[i + gap], &array[i]);
			}
		}
	
	}
}
