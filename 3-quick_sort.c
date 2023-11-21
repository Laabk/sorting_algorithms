#include "sort.h"

void swap_intergs(int *a, int *b);
int lom_partition(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
void lom_sort(int *array, size_t size, int left, int right);

/**
 * swap_intergs - Swaping two integers in an array.
 * @a: The first integer to be swaped
 * @b: second integer to be swaprd
 */
void swap_intergs(int *a, int *b)
{
	int nw;

	nw = *a;
	*a = *b;
	*b = nw;
}

/**
 * lom_sort - uses the quicksort algorithm to sort through recursion.
 * @array: the array of integers to be sorted
 * @size: size of an array involved
 * @left: ffirst index of the array partition to order.
 * @right: last index of the array partition to order.
 */
void lom_sort(int *array, size_t size, int left, int right)
{
	int sam;

	if (right - left > 0)
	{
		sam = lom_partition(array, size, left, right);
		lom_sort(array, size, left, sam - 1);
		lom_sort(array, size, sam + 1, right);
	}
}

/**
 * quick_sort - this function Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: the array of size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lom_sort(array, size, 0, size - 1);
}

/**
 * lom_partition - sorts Order the subset of array of integers according
 * tothe lomuto partition scheme
 * @array: array of integers.
 * @size: size of array.
 * @left: first index of subset to order.
 * @right: last index of subset to order.
 *
 * Return: last partition index.
 */
int lom_partition(int *array, size_t size, int left, int right)
{
	int *t, top, low;

	t = array + right;
	for (top = low = left; low < right; low++)
	{
		if (array[low] < *t)
		{
			if (top < low)
			{
				swap_intergs(array + low, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *t)
	{
		swap_intergs(array + top, t);
		print_array(array, size);
	}

	return (top);
}
