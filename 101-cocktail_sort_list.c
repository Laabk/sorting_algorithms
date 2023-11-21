#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);

/**
 * swap_node_ahead - this func swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @list: head pointr of a doubly-linked list of integers.
 * @tail: pointer to tail of doubly-linked list.
 * @shaker: pointer to current swapping node of the cocktail shaker
 */

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *nw = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = nw;
	else
		*list = nw;
	nw->prev = (*shaker)->prev;
	(*shaker)->next = nw->next;
	if (nw->next != NULL)
		nw->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = nw;
	nw->next = *shaker;
	*shaker = nw;
}

/**
 * cocktail_sort_list - this func sortes a listint_t doubly-linked list
 * of integers
 * in ascending order using the cocktail shaker algorithm.
 * @list: the head pointer of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *til, *shr;
	bool shaken = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (til = *list; til->next != NULL;)
		til = til->next;

	while (shaken == false)
	{
		shaken = true;
		for (shr = *list; shr != til; shr = shr->next)
		{
			if (shr->n > shr->next->n)
			{
				swap_node_ahead(list, &til, &shr);
				print_list((const listint_t *)*list);
				shaken = false;
			}
		}
		for (shr = shr->prev; shr != *list;
				shr = shr->prev)
		{
			if (shr->n < shr->prev->n)
			{
				swap_node_behind(list, &til, &shr);
				print_list((const listint_t *)*list);
				shaken = false;
			}
		}
	}
}

/**
 * swap_node_behind - this func swapes a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 * @list: the head pointer of a doubly-linked list of integers.
 * @tail: pointer to tail of the doubly-linked list.
 * @shaker: ointer to current swapping node of the cocktail shaker algo.
 */

void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *nw = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = nw;
	else
		*tail = nw;
	nw->next = (*shaker)->next;
	(*shaker)->prev = nw->prev;
	if (nw->prev != NULL)
		nw->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = nw;
	nw->prev = *shaker;
	*shaker = nw;
}

