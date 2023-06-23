#include "sort.h"

/**
 * insertion_sort_list - insertion sorting method
 * @list: linkded list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = NULL, *temp = NULL;

	if (!list || !(*list))
		return;

	ptr = temp = (*list)->next;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list(*list);
		}
		temp = ptr;
	}
}
