#include "sort.h"

/**
 * swap_intergs - this changes or swap two integers in an array.
 * @a: first integer to beswaped
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
 * bubble_sort - this sort an array of integers in ascending order.
 * @array: array of integers to sort.
 * @size: the array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t d, lent = size;
	bool bub = false;

	if (array == NULL || size < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (d = 0; d < lent - 1; d++)
		{
			if (array[d] > array[d + 1])
			{
				swap_intergs(array + d, array + d + 1);
				print_array(array, size);
				bub = false;
			}
		}
		lent--;
	}
}
