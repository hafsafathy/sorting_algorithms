#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - function that sorts an array of
 * integers in ascending order using the Selection sort algorithm
 * @array: array
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, k, b;
	int t;

	for (k = 0; k < size - 1; k++)
	{
		b = k;
		for (i = k + 1; i < size; i++)
		{
			if (array[i] < array[b])
				b = i;
		}

		if (b != k)
		{
			t = array[k];
			array[k] = array[b];
			array[b] = t;
			print_array(array, size);
		}
	}
}
