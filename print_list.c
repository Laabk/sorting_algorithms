#include <stdio.h>
#include "sort.h"

/**
 * print_list - this func prints a list of integers involved
 * @list: stored list to be printed out
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
