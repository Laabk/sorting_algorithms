#include "sort.h"

/**
 * swap_intergs - Swapping or changing two integers in an array.
 * @a: The first integer to be swaped
 * @b: second integer to be swaped
 */

void swap_intergs(int *a, int *b)
{
	int nw;

	nw = *a;
	*a = *b;
	*b = nw;
}

/**
 * selection_sort -  this func sorts an array of integers in ascending
 * orderusing the selection sort algorithm.
 * @array: An array of integers.
 * @size: the array sizes
 */

void selection_sort(int *array, size_t size)
{
	int *sma;
	size_t d, m;

	if (array == NULL || size < 2)
		return;

	for (d = 0; d < size - 1; d++)
	{
		sma = array + d;
		for (m = d + 1; m < size; m++)
			sma = (array[m] < *sma) ? (array + m) : sma;

		if ((array + d) != sma)
		{
			swap_intergs(array + d, sma);
			print_array(array, size);
		}
	}
}
