#include "sort.h"
#include <stdio.h>

/**
 * swaps - swaps 2 item
 * @array: array
 * @r: right index
 * @l: left index
 * Return: Nothing
 */
void swaps(int *array, int r, int l)
{
	int t;

	if (array[r] != array[l])
	{
		t = array[r];
		array[r] = array[l];
		array[l] = t;
	}
}

/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Shell sort algorithm
 * , using the Knuth sequence
 * @array: array
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 0,  i, j;

	if (size < 2)
		return;

	while (n <= size / 3)
		n = n * 3 + 1;

	while (n >= 1)
	{
		for (i = n; i < size; i++)
			for (j = i; j >= n && array[j] < array[j - n]; j -= n)
				swaps(array, j, j - n);
		n /= 3;
		print_array(array, size);
	}
}
