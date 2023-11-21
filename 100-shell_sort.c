#include "sort.h"

/**
 * swap_intergs - this swaps two integers in an array.
 * @a: first integer to be swaped
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
 * shell_sort - this func sortes an array of integers in
 * ascending order using the shell sort algorithm.
 * @array: array of integers.
 * @size: the array of size
 */

void shell_sort(int *array, size_t size)
{
	size_t sp, d, m;

	if (array == NULL || size < 2)
		return;

	for (sp = 1; sp < (size / 3);)
		sp = sp * 3 + 1;

	for (; sp >= 1; sp /= 3)
	{
		for (d = sp; d < size; d++)
		{
			m = d;
			while (m >= sp && array[m - sp] > array[m])
			{
				swap_intergs(array + m, array + (m - sp));
				m -= sp;
			}
		}
		print_array(array, size);
	}
}
