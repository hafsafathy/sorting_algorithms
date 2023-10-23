#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p, *t;

	if (!list)
		return;

	p = *list;

	while (p)
	{
		while (p->next && (p->n > p->next->n))
		{
			t = p->next;
			p->next = t->next;
			t->prev = p->prev;

			if (p->prev)
				p->prev->next = t;

			if (t->next)
				t->next->prev = p;

			p->prev = t;
			t->next = p;

			if (t->prev)
				p = t->prev;
			else
				*list = t;

			print_list(*list);
		}
		p = p->next;
	}
}
