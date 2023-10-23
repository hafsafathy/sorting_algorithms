#include "sort.h"

/**
  * shell_sort - function that sorts an array of integers in
  * ascending order using the Shell sort algorithm, using the Knuth sequence
  * @array: array.
  * @size: length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, k = 0;
	int a = 0;

	if (array == NULL || size < 2)
		return;

	while (k < size / 3)
		k = k * 3 + 1;

	for (; k > 0; k = (k - 1) / 3)
	{
		for (i = k; i < size; i++)
		{
			a = array[i];
			for (j = i; j >= k && array[j - k] > a;
					j -= k)
			{
				if (array[j] != array[j - k])
					array[j] = array[j - k];
			}
			if (array[j] != a)
				array[j] = a;

		}
		print_array(array, size);
	}
}
