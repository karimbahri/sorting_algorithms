#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap - function to swap nodes
 * @listx: pointer to the list to sort
 * @tempo: pointer to the node to swap
 */

void swap_node(listint_t **listx, listint_t *tempo)
{
	listint_t *reference = NULL;

	reference = tempo;
	if (temp->next != NULL)
		temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	temp->next = temp->prev;
	temp->prev = temp->prev->prev;
	temp->next->prev = temp;
	if (temp->prev == NULL)
		*list = temp;
	temp->prev->next = temp;
}

/**
 * cocktail_sort_list - sort a dll using cocktail sort
 * @list: pointer to ze first element of ze list
 */


void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = NULL;
	size_t flag;

	temp = *list;

	while (temp)
	{
		flag = 0;

		while (temp->next)
		{
			if (temp->n < temp->next->n)
				swap(list, temp);
				temp = temp->next
				falg = 1;
		}

		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
				swap(temp);
				temp = temp->prev;
				flag = 1;
		}

			if (flag1 == 0 && flag2 == 0)
				break;

	}
}
