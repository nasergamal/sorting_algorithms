#include "sort.h"


/**
 * shell_sort - shell sorting method
 * @array: the array to be sorted
 * @size: array size
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, n;
	int tmp;

	for (gap = 1; gap < size; gap = gap * 3 + 1)
		;
	for (gap /= 3; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (n = i; n >= gap; n -= gap)
			{
				if (array[n - gap] > tmp)
					array[n] = array[n - gap];
				else
					break;
			}
			array[n] = tmp;

		}
		print_array(array, size);
	}
}

