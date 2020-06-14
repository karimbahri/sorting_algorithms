#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorting array using selection algorithm
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int posMin;
	size_t i = 0, j = 0;

	if (!array)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		posMin = i;
		for (j = i + 1 ; j < size ; j++)
		{
			if (array[j] < array[posMin])
				posMin = j;
		}
		if ((size_t)posMin != i)
		{
			swap(&array[i], &array[posMin]);
			print_array(array, size);
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
