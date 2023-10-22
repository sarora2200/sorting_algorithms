#include "sort.h"

/**
 * swapAhead - SwapDoubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: head pointer of a doubly-linked list of integers.
 * @ta: tail pointer of the doubly-linked list.
 * @sh: current swapping pointer  node of the cocktail.
 */
void swapAhead(listint_t **list, listint_t **ta, listint_t **sh)
{
	listint_t *t = (*sh)->next;

	if ((*sh)->prev != NULL)
		(*sh)->prev->next = t;
	else
		*list = t;
	t->prev = (*sh)->prev;
	(*sh)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *sh;
	else
		*ta = *sh;
	(*sh)->prev = t;
	t->next = *sh;
	*sh = t;
}

/**
 * swapBehind - SwapDoubly-linked
 *                    list of integers with the node behind it.
 * @list: head pointer of a doubly-linked list of integers.
 * @ta: tail pointer of the doubly-linked list.
 * @sh: current pointer swapping node of the cocktail.
 */
void swapBehind(listint_t **list, listint_t **ta, listint_t **sh)
{
	listint_t *t = (*sh)->prev;

	if ((*sh)->next != NULL)
		(*sh)->next->prev = t;
	else
		*ta = t;
	t->next = (*sh)->next;
	(*sh)->prev = t->prev;
	if (t->prev != NULL)
		t->prev->next = *sh;
	else
		*list = *sh;
	(*sh)->next = t;
	t->prev = *sh;
	*sh = t;
}

/**
 * cocktail_sort_list - SortDoubly-linked list of integers in
 *                      ascending order using the cocktailAlgorithm.
 * @list: head pointer of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ta, *sh;
	bool Not_statred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (ta = *list; ta->next != NULL;)
		ta = ta->next;

	while (Not_statred == false)
	{
		Not_statred = true;
		for (sh = *list; sh != ta; sh = sh->next)
		{
			if (sh->n > sh->next->n)
			{
				swapAhead(list, &ta, &sh);
				print_list((const listint_t *)*list);
				Not_statred = false;
			}
		}
		for (sh = sh->prev; sh != *list;
				sh = sh->prev)
		{
			if (sh->n < sh->prev->n)
			{
				swapBehind(list, &ta, &sh);
				print_list((const listint_t *)*list);
				Not_statred = false;
			}
		}
	}
}
