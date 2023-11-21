#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

#define UP 0
#define DOWN 1

/**
 * enum bool - this funct enumerates Boolean values.
 * @false: if is equals 0.
 * @true: if is equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - the doubly linked list node function
 * @n: the integer that has beenstored in the node
 * @prev: the Pointer to previous element involved the list
 * @next: the pointer to next element involved in the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

#endif
