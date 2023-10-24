#include "sort.h"

/**
 * swaps - Swaps two item
 * @nde: node
 * @lst: list head
 * Return: No Return
 */
void swaps(listint_t **nde, listint_t **lst)
{
	listint_t *t = *nde, *t2, *t3;


	if (!(*nde)->prev)
		*lst = (*nde)->next;

	t = t3 = *nde;
	t2 = t->next;

	t->next = t2->next;
	t3 = t->prev;
	t->prev = t2;
	t2->next = t;
	t2->prev = t3;

	if (t2->prev)
		t2->prev->next = t2;


	if (t->next)
		t->next->prev = t;

	*nde = t2;

}
/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail
 * shaker sort algorithm
 * @list: head of list
 * Return: No Return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *a;
	int c = 0, i = -1, j = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (j >= i)
	{
		i++;
		while (head->next && c != j)
		{
			if (head->n > head->next->n)
			{
				a = head;
			       swaps(&a, list);
			       print_list(*list);
			       head = a;
			}

			c++;
			head = head->next;
		}

		if (i == 0)
			j = c;
		j--;
		while (head->prev && c >= i)
		{
			if (head->n < head->prev->n)
			{
				a = head->prev;
				swaps(&a, list);
				print_list(*list);
				head = a->next;
			}
			c--;
			head = head->prev;
		}
	}
}
