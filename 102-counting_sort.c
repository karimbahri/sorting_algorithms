#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorting array using counting algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *sorted;
	int k = findMax(array, size);
	int i;

	if (!array || size < 2)
		return;

	counting_array = malloc(sizeof(size_t) * (k + 1));
	if (!counting_array)
		return;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;

	fillZero(counting_array, k + 1);
	countOccur(counting_array, array, size);

	for (i = 1 ; i < (k + 1) ; i++)
		counting_array[i] += counting_array[i - 1];

	print_array(counting_array, k + 1);

	for (i = (int)size - 1 ; i > -1 ; i--)
	{
		sorted[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	assignArray(array, sorted, size);

	free(counting_array);
	free(sorted);
}

/**
 * findMax - find the maxElement in given array
 * @array: array to check
 * @size: size of the array
 * Return: max
 */
int findMax(int array[], size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1 ; i < size ; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * fillZero - fill array with the value zero
 * @array: array to fill
 * @size: size of the array
 */
void fillZero(int array[], size_t size)
{
	size_t i;

	for (i = 0 ; i < size ; i++)
		array[i] = 0;
}

/**
 * countOccur - count number of occurrence in an array
 * @countArray: array to check
 * @array: first array
 * @size: size of the array
 */
void countOccur(int countArray[], int array[], size_t size)
{
	size_t i;

	for (i = 0 ; i < size ; i++)
		countArray[array[i]]++;
}

/**
 * assignArray - copy the value of an array into another
 * @array1: array to assign
 * @array2: source
 * @size: size of the array
 */
void assignArray(int array1[], int array2[], size_t size)
{
	size_t i;

	for (i = 0 ; i < size ; i++)
		array1[i] = array2[i];
}
