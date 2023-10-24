#include "sort.h"
/**
 * check - check
 * @array: array
 * @size: size of the array
 * @ORsize: original size of the array
 * @i: index
**/
void check(int *array, size_t ORsize, size_t size, size_t i)
{

	int n, b, b1;
	size_t p, p1;

	p = i * 2 + 1;
	p1 = p + 1;
	b = array[p];
	b1 = array[p1];
	if (((p < size) && (p1 < size) &&
		(b >= b1 && b > array[i]))
		|| ((p == size - 1) && b > array[i]))
	{
		n = array[i];
		array[i] = b;
		array[p] = n;
		print_array(array, ORsize);
	}
	else if ((p < size) && (p1 < size) &&
		(b1 > b && b1 > array[i]))
	{
		n = array[i];
		array[i] = b1;
		array[p1] = n;
		print_array(array, ORsize);
	}
	if (p < size - 1)
		check(array, ORsize, size, p);
	if (p1 < size - 1)
		check(array, ORsize, size, p1);
}
/**
 * heap_sort - function that sorts an array of integers
 * in ascending order using the Heap
 * sort algorithm
 * @array: array
 * @size: size of the array
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t i, ORsize = size;
	int n;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check(array, ORsize, size, size / 2 - 1 - i);
	}
	for (i = 0; i < ORsize - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, ORsize);
		check(array, ORsize, size - i - 1, 0);
	}

}
