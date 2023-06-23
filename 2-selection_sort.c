#include "sort.h"


/**
 * selection_sort - selection sorting method
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, n, smallest;
	int temp;

	if (!array || !(*array))
		return;

	for (i = 0; i < size; i++)
	{
		smallest = i;
		for (n = i; n < size; n++)
		{
			if (array[smallest] > array[n])
				smallest = n;
		}
		if (smallest != i)
		{
			temp = array[i];
			array[i] = array[smallest];
			array[smallest] = temp;
			print_array(array, size);
		}
	}
}
