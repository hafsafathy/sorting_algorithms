#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - function that sorts an array of
 *  integers in ascending order using the Merge sort algorithm
 * @array: array
 * @size: size of the array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *b = NULL;

	if (array == NULL || size < 2)
		return;
	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;
	for (; i < size; i++)
		b[i] = array[i];
	mergePart(0, size, array, b);
	free(b);
}

/**
 * merge - function that sorts the subarrays.
 * @dwn: Lower index.
 * @m: Middle index.
 * @top: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * Return: Nothing
 */
void merge(size_t dwn, size_t m, size_t top, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + dwn, m - dwn);
	printf("[right]: ");
	print_array(src + m, top - m);
	i = dwn;
	j = m;
	k = dwn;
		for (; k < top; k++)
		{
			if (i < m && (j >= top || src[i] <= src[j]))
			{
				dest[k] = src[i];
				i++;
			}
			else
			{
				dest[k] = src[j];
				j++;
			}
		}
	printf("[Done]: ");
	print_array(dest + dwn, top - dwn);
}

/**
 * mergePart - funtion that splits the array.
 * @dwn: lower index.
 * @top: higher index.
 * @array: array to sort.
 * @b: copy of the array.
 * Return: Nothing.
 */
void mergePart(size_t dwn, size_t top, int *array, int *b)
{
	size_t m = 0;

	if (top - dwn < 2)
		return;
	m = (dwn + top) / 2;
	mergePart(dwn, m, array, b);
	mergePart(m, top, array, b);
	merge(dwn, m, top, array, b);
	for (m = dwn; m < top; m++)
		b[m] = array[m];
}
