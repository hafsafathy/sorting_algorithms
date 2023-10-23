#include "sort.h"

/**
 * swaps - Swaps two items
 * @array: array
 * @l_indx: left item.
 * @r_indx: right item.
 */
void swaps(int *array, size_t l_indx, size_t r_indx)
{
	int t;

	if (array != NULL)
	{
		t = array[l_indx];
		array[l_indx] = array[r_indx];
		array[r_indx] = t;
	}
}

/**
 * quicks - Sorts a sub array
 * @array: array
 * @start: start
 * @end: end
 * @size: The length of the array.
 */
void quicks(int *array, size_t start, size_t end, size_t size)
{
	size_t j, i;
	int p;

	if ((start >= end) || (array == NULL))
		return;
	p = array[end];
	j = start;
	for (i = start; i < end; i++)
	{
		if (array[i] <= p)
		{
			if (j != i)
			{
				swaps(array, j, i);
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != end)
	{
		swaps(array, j, end);
		print_array(array, size);
	}
	if (j - start > 1)
		quicks(array, start, k - 1, size);
	if (end - k > 1)
		quicks(array, j + 1, end, size);
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * @array: array.
 * @size: length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quicks(array, 0, size - 1, size);
	}
}
