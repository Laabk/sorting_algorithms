#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - this func prints an array of integers
 * @array: The array of numbesto be printed out
 * @size: the number of elements stored in @array
 */
void print_array(const int *array, size_t size)
{
	size_t d;

	d = 0;
	while (array && d < size)
	{
		if (d > 0)
			printf(", ");
		printf("%d", array[d]);
		++d;
	}
	printf("\n");
}
