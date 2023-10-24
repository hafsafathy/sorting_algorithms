#include "sort.h"

/**
* swaps - swaps two element
* @array: array
* @itm1: array element
* @itm2: array element
*/
void swaps(int *array, ssize_t itm1, ssize_t itm2)
{
	int t;

	t = array[itm1];
	array[itm1] = array[itm2];
	array[itm2] = t;
}
/**
 * hoare_part - hoare partition sorting
 * @array: array
 * @f: first array element
 * @lst: last array element
 * @size: size array
 * Return: return the position of the last element sorted
 */
int hoare_part(int *array, int f, int lst, int size)
{
	int c = f - 1, fn = lst + 1;
	int pivot = array[lst];

	while (1)
	{

		do {
			c++;
		} while (array[c] < pivot);
		do {
			fn--;
		} while (array[fn] > pivot);
		if (c >= fn)
			return (c);
		swaps(array, c, fn);
		print_array(array, size);
	}
}
/**
 * queq - qucksort algorithm
 * @array: array
 * @f: first array element
 * @lst: last array element
 * @size: array size
 */
void queq(int *array, ssize_t f, ssize_t lst, int size)
{
	ssize_t p = 0;

	if (f < lst)
	{
		p = hoare_part(array, f, lst, size);
		queq(array, f, p - 1, size);
		queq(array, p, lst, size);
	}
}
/**
 * quick_sort_hoare - prepare the terrain to quicksort algorithm
 * @array: array
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	queq(array, 0, size - 1, size);
}
