#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorting array using bubble algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	bool sorted = FALSE;

	if (!array)
		return;

	while (!sorted)
	{
		sorted = TRUE;
		for (i = 0 ; i < size - 1 ; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				sorted = FALSE;
				print_array(array, size);
			}
		}
	}
}

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
