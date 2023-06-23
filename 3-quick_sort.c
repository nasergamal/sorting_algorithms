#include "sort.h"
void qs(int *array, int low, int high, size_t size);
size_t lomuto(int *array, int low, int high, size_t size);

/**
 * quick_sort - quick-sort sorting method
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	 qs(array, 0, size - 1, size);
}

/**
 * qs - quick-sort complementing function
 * @array: array to be sorted
 * @low: sort start
 * @high: sort end
 * @size: array size
 *
 * Return: void
 */

void qs(int *array, int low, int high, size_t size)
{
	size_t part;

	if (low < high)
	{
		part = lomuto(array, low, high, size);
		qs(array, low, part - 1, size);
		qs(array, part + 1, high, size);
	}
}

/**
 * lomuto - quick-sort lomuto method
 * @array: array to be sorted
 * @low: sort start
 * @high: sort end
 * @size: array size
 *
 * Return: void
 */
size_t lomuto(int *array, int low, int high, size_t size)
{
	int n, i;
	int tmp, pivot;

	pivot = array[high];
	i = low - 1;
	for (n = low; n <= high - 1; n += 1)
	{
		if (array[n] < pivot)
		{
			i++;
			if (i != n)
			{
				tmp = array[i];
				array[i] = array[n];
				array[n] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{	tmp = array[high];
		array[high] = array[i + 1];
		array[i + 1] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
