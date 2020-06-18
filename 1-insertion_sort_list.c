#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sort a list
 * @list: pointer to the head of ze list
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL;
	listint_t *reference = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = (*list)->next;
	while (temp)
	{
		reference = temp;
		while (temp->prev && (temp->n < temp->prev->n))
		{
			if (temp->next)
		{
			temp->next->prev = temp->prev;
		}
		temp->prev->next = temp->next;
		temp->next = temp->prev;
		temp->prev = temp->prev->prev;
		temp->next->prev = temp;
		if (temp->prev == NULL)
		{
			*list = temp;
		}
		else
			temp->prev->next = temp;
			print_list(*list);
		}
		temp = reference->next;

		}
}
