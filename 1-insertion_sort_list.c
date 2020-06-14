#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *temp = NULL;
    listint_t *reference = NULL;

    temp = (*list)->next;
    while(temp)
    {
        reference = temp;
        while(temp->prev && (temp->n < temp->prev->n))
        {
            if(temp->next)
            {
                temp->next->prev = temp->prev;
            }
            temp->prev->next = temp->next;
            temp->next = temp->prev;
            temp->prev = temp->prev->prev;
            temp->next->prev = temp;
            if(temp->prev == NULL)
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
