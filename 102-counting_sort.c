#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: array
 * @size: size of array
 **/
void counting_sort(int *array, size_t size)
{
	int k, j, *carray, *a;
	size_t i;

	if (!array || size < 2)
		return;
	k = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	carray = calloc((k + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		carray[array[i]]++;
	}
	for (j = 1; j < k; j++)
	{
		carray[j + 1] += carray[j];
	}
	print_array(carray, k + 1);
	a = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		carray[array[i]]--;
		a[carray[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = a[i];
	}
	free(a);
	free(carray);
}
