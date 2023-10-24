#include <stdlib.h>
#include "sort.h"

/**
 * sort - function of radix sort
 * @array: array of data to be sorted
 * @buff: malloc buffer
 * @size: size of data
 * @less: less digit
 * Return: No Return
 */
void sort(int *array, int **buff, int size, int less)
{
	int i, j, cs = 10, num;
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < less; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buff[num][arr[num]] = array[i];
		arr[num] += 1;
	}

	for (i = 0, j = 0; i < cs; i++)
	{
		while (arr[i] > 0)
		{
			array[j] = buff[i][arr2[i]];
			arr2[i] += 1, arr[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}
/**
 * sorts - function of radix sort
 * @array: array of data
 * @size: size of data
 * @less: less digit
 * Return: No Return
 */
void sorts(int *array, int size, int less)
{
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, num, cs = 10, **buff;

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < less; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		arr[num] += 1;
	}

	if (arr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < cs; i++)
		if (arr[i] != 0)
			buff[i] = malloc(sizeof(int) * arr[i]);


	sort(array, buff, size, less);

	sorts(array, size, less + 1);

	for (i = 0; i < cs; i++)
		if (arr[i] > 0)
			free(buff[i]);
	free(buff);
}
/**
 * radix_sort -  function that sorts an array of integer
 * in ascending order using the Radix sort algorithm
 * @array: array
 * @size: size
 * Return: No Return
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
