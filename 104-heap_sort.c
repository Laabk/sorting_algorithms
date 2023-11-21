#include "sort.h"

void swap_intergs(int *a, int *b);
void heap_sort(int *array, size_t size);
void max_hernumb(int *array, size_t size, size_t base, size_t root);

/**
 * swap_intergs - this func swap two integers in an array.
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
 * max_hernumb - this funcchange a binary tree into a complete binary heap.
 * @array: array of integers for binary tree.
 * @size: size of array/tree.
 * @base: index of base row of tree.
 * @root: root node of binary tree.
 */

void max_hernumb(int *array, size_t size, size_t base, size_t root)
{
	size_t left, big, right;

	left = 2 * root + 1;
	right = 2 * root + 2;
	big = root;

	if (left < base && array[left] > array[big])
		big = left;
	if (right < base && array[right] > array[big])
		big = right;

	if (big != root)
	{
		swap_intergs(array + root, array + big);
		print_array(array, size);
		max_hernumb(array, size, base, big);
	}
}

/**
 * heap_sort - this func sort an array of integers in
 * ascendingorder using the heap sort algorithm.
 * @array: array of involved integers.
 * @size: the array of size
 */

void heap_sort(int *array, size_t size)
{
	int d;

	if (array == NULL || size < 2)
		return;

	for (d = (size / 2) - 1; d >= 0; d--)
		max_hernumb(array, size, size, d);

	for (d = size - 1; d > 0; d--)
	{
		swap_intergs(array, array + d);
		print_array(array, size);
		max_hernumb(array, size, d, 0);
	}
}
