#include "sort.h"

/**
 * swap_the_nodes - this swap two nodes in a listint_t doubly-linked list.
 * @h: head pointerof the doubly-linked list.
 * @n1: pointer to the first node to swap.
 * @n2: second node to swap.
 */
void swap_the_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - this func sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: head pointerof a doubly-linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *chang, *put, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (chang = (*list)->next; chang != NULL; chang = tmp)
	{
		tmp = chang->next;
		put = chang->prev;
		while (put != NULL && chang->n < put->n)
		{
			swap_the_nodes(list, &put, chang);
			print_list((const listint_t *)*list);
		}
	}
}
