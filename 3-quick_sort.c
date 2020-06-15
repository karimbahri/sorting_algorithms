#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort_function - sorting array using quick sort algorithm
 * @array: array
 * @begin: beginning
 * @end: ending
 * @size: size of the array
 */
void quick_sort_function(int *array, int begin, int end, size_t size)
{
	int pos;

	if (begin < end)
	{
		pos = partition(array, begin, end, size);

		quick_sort_function(array, begin, pos - 1, size);

		quick_sort_function(array, pos + 1, end, size);
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

/**
 * partition - partition the array
 * @array: array
 * @begin: beginning
 * @end: ending
 * @size: size of the array
 * Return: pos
 */
int partition(int array[], int begin, int end, size_t size)
{
	int pivot = array[end], pos = begin - 1;
	int i = 0;

	for (i = begin ; i < end ; i++)
		if (array[i] <= pivot)
		{
			pos++;
			swap(&array[pos], &array[i]);
			if (pos != i)
				print_array(array, size);
		}
	swap(&array[end], &array[pos + 1]);
	if (end != (pos + 1))
		print_array(array, size);
	return (pos + 1);
}

/**
 * quick_sort - sorting array using quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_function(array, 0, size - 1, size);
}
