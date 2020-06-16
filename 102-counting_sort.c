#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort(int *array, size_t size)
{
	int *counting_array, *sorted;
	int k = findMax(array, size);
	int i;

	if (!array || size < 2)
		return;

	counting_array = malloc(sizeof(int) * (k + 1));
	sorted = malloc(sizeof(int) * size);
	if (!counting_array || !sorted)
		return;

	fillZero(counting_array, k + 1);
	countOccur(counting_array, array, size);

	for (i = 0 ; i < (k + 1) ; i++)
		counting_array[i] += counting_array[i - 1];

	print_array(counting_array, k + 1);

	for (i = (int)size - 1 ; i > -1 ; i--)
	{
		sorted[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	assignArray(array, sorted, size);
}

int findMax(int array[], size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1 ; i < size ; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

void fillZero(int array[], size_t size)
{
	size_t i;

	for (i = 0 ; i < size ; i++)
		array[i] = 0;
}

void countOccur(int countArray[], int array[], size_t size)
{
	size_t i;

	for (i = 0 ; i < size ; i++)
		countArray[array[i]]++;
}

void assignArray(int array1[], int array2[], size_t size)
{
	size_t i;

	for (i = 0 ; i < size ; i++)
		array1[i] = array2[i];
}
