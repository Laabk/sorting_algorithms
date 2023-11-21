#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_array - this funct prints an array of integers stored
 * @array: array to be printed out
 * @size:the number of elements storedin @array
 */
void print_the_array(const int *array, size_t size)
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

/**
 * print_list - this funct prints a list of integers stored
 * @list: involved list to be printed
 */

void print_list(const listint_t *list)
{
	int d;

	d = 0;
	while (list)
	{
		if (d > 0)
			printf(", ");
		printf("%d", list->n);
		++d;
		list = list->next;
	}
	printf("\n");
}
