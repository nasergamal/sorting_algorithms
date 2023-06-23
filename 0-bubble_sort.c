#include "sort.h"

/**
 * bubble_sort - bubble sorting method
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int temp, swap = 0;
	size_t i, n, siz;

	if (!(array) || !(*array))
		return;
	siz = size;
	for (i = 0 ; i < size - 1; i++)
	{
		swap = 0;
		for (n = 0 ; n < siz - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				swap = 1;
				temp = array[n];
				array[n] =  array[n + 1];
				array[n + 1] = temp;
				print_array(array, size);
			}
		}
		siz--;
		if (swap == 0)
			return;
	}

}
