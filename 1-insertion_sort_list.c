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

	ptr = *list;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->n < ptr->prev->n)
		{
			temp = ptr;
			while (temp->prev)
			{
				if (ptr->n < temp->prev->n)
					temp = temp->prev;
				else
					break;
			}
			ptr->prev->next = ptr->next;
			if (ptr->next)
				ptr->next->prev = ptr->prev;
			if (temp->prev)
				temp->prev->next = ptr;
			else
				*list = ptr;
			ptr->prev = temp->prev;
			temp->prev = ptr;
			ptr->next = temp;
			print_list(*list);
		}
		ptr = ptr->next;
	}
}
