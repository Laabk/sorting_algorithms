#include "sort.h"

/**
 * get_maxim - takes maximum digits in an array of integers.
 * @array: array of integers.
 * @size: the array of size
 * Return: the highest digits
 */
int get_maxim(int *array, int size)
{
	int maxin, d;

	for (maxin = array[0], d = 1; d < size; d++)
	{
		if (array[d] > maxin)
			maxin = array[d];
	}

	return (maxin);
}

/**
 * counting_sort - this func sortes an array of integers in ascending
 * orderusing the counting sort algorithm.
 * @array: array of integers.
 * @size: the array of size
 */
void counting_sort(int *array, size_t size)
{
	int *numbs, *sort, maxin, d;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	maxin = get_maxim(array, size);
	numbs = malloc(sizeof(int) * (maxin + 1));
	if (numbs == NULL)
	{
		free(sort);
		return;
	}

	for (d = 0; d < (maxin + 1); d++)
		numbs[d] = 0;
	for (d = 0; d < (int)size; d++)
		numbs[array[d]] += 1;
	for (d = 0; d < (maxin + 1); d++)
		numbs[d] += numbs[d - 1];
	print_array(numbs, maxin + 1);

	for (d = 0; d < (int)size; d++)
	{
		sort[numbs[array[d]] - 1] = array[d];
		numbs[array[d]] -= 1;
	}

	for (d = 0; d < (int)size; d++)
		array[d] = sort[d];

	free(sort);
	free(numbs);
}
