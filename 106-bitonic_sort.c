#include "sort.h"
#include <stdio.h>

/**
 * swaps - swaps two item
 * @array: array
 * @itm1: item one
 * @itm2: item two
 * @ord: 1: order, 0 order
 * Return: nothing
 */
void swaps(int array[], int itm1, int itm2, int ord)
{
	int t;

	if (ord == (array[itm1] > array[itm2]))
	{
		t = array[itm1];
		array[itm1] = array[itm2];
		array[itm2] = t;
	}
}
/**
 * merge - sort bitonic in orders
 * @array: array
 * @dwn: low element
 * @num: number
 * @ord: 1: order, 0 order
 * Return: nothing
 */
void merge(int array[], int dwn, int num, int ord)
{
	int m, i;

	if (num > 1)
	{
		m = num / 2;
		for (i = dwn; i < dwn + m; i++)
			swaps(array, i, i + m, ord);
		merge(array, dwn, m, ord);
		merge(array, dwn + m, m, ord);
	}
}
/**
 * bitonicsort - bitonic sort algorithm
 * @array: array
 * @dwn: first element
 * @num: number of elements
 * @ord: 1: order, 0 order
 * @size: array lenght
 * Return: nothing
 */
void bitonicsort(int array[], int dwn, int num, int ord, int size)
{
	int m;

	if (num > 1)
	{
		if (ord >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", num, size);
			print_array(&array[dwn], num);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", num, size);
			print_array(&array[dwn], num);
		}
		m = num / 2;
		bitonicsort(array, dwn, m, 1, size);
		bitonicsort(array, dwn + m, m, 0, size);
		merge(array, dwn, num, ord);
		if (ord <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", num, size);
			print_array(&array[dwn], num);
		}
		if (ord >= 1)
		{
			printf("Result [%i/%i] (UP):\n", num, size);
			print_array(&array[dwn], num);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int ord = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, ord, size);
}
