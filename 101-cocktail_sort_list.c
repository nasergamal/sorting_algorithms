#include "sort.h"

void swap(listint_t *ptr, listint_t *tmp, int flag);
/**
 * cocktail_sort_list - cocktail sorting method
 * @list: linked list to be sorted
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr = NULL, *tmp = NULL;
	int sort = 0;

	if (!list || !(*list))
		return;
	ptr = tmp = *list;
	while (ptr)
	{	sort = 0;
		while (ptr)
		{
			if (ptr->n >= tmp->n)
				tmp = ptr;
			else
			{
				if (tmp->prev == NULL)
					*list = ptr;
				swap(ptr, tmp, 1);
				print_list(*list), sort = 1; }
			if (ptr->next == NULL)
				break;
			ptr = ptr->next;
		}
		tmp = ptr;
		while (ptr)
		{
			if (ptr->n <= tmp->n)
				tmp = ptr;
			else
			{
				if (ptr->prev == NULL)
					*list = tmp;
				swap(ptr, tmp, 2);
				print_list(*list), sort = 1; }
			if (ptr->prev == NULL)
				break;
			ptr = ptr->prev;
		}
		if (ptr->prev == NULL)
			*list = ptr;
		tmp = ptr;
		if (sort == 0)
			break;
	}
}

/**
 * swap - swap nodes of the linked list
 * @ptr: the current node in linked list
 * @tmp: the node to swap place with ptr
 * @flag: 1 for forward movement in linked list 2 otherwise
 *
 * Return: void
 */
void swap(listint_t *ptr, listint_t *tmp, int flag)
{
	if (flag == 1)
	{
		if (tmp->prev)
			tmp->prev->next = ptr;
		if (ptr->next)
			ptr->next->prev = tmp;
		tmp->next = ptr->next;
		ptr->next = tmp, ptr->prev = tmp->prev;
		tmp->prev = ptr;
		ptr = tmp;
	}
	else
	{
		if (tmp->next)
			tmp->next->prev = ptr;
		if (ptr->prev)
			ptr->prev->next = tmp;
		tmp->prev = ptr->prev;
		ptr->prev = tmp;
		ptr->next = tmp->next;
		tmp->next = ptr;
		ptr = tmp;
	}
}
