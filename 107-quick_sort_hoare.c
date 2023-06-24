#include "sort.h"
void swap(int *a, int l, int h, size_t size);
void qsh(int *array, int low, int high, size_t size);
int hoare(int *array, int low, int high, size_t size);

/**
 * quick_sort_hoare - quick sort algorithm using hoare partition
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qsh(array, 0, size - 1, size);
}

/**
 * qsh - quick sort auxiliary funciton
 * @array: array to be sorted
 * @low: sort start point
 * @high: sort end point
 * @size: array size
 *
 * Return: void
 */

void qsh(int *array, int low, int high, size_t size)
{
	int part;

	if (low < high)
	{
		part = hoare(array, low, high, size);

		qsh(array, low, part, size);
		qsh(array, part + 1, high, size);
	}
}


/**
 * hoare - hoare partition
 * @array: array to be sorted
 * @low: sort start point
 * @high: sort end point
 * @size: array size
 *
 * Return: partition
 */

int hoare(int *array, int low, int high, size_t size)
{
	int l = low, h = high;
	int pivot = array[high];

	while (l <= h)
	{
		while (array[l] < pivot)
		{
			l++;
		}
		while (array[h] > pivot)
		{
			h--;
		}
		if (l <= h)
		{
			if (l != h)
				swap(array, l, h, size);
			l++;
			h--;
		}
	}
	return (h);
}

/**
 * swap - swap two element in array
 * @a: array
 * @l: 1st element
 * @h: 2nd element
 * @size: array size
 *
 * Return: void
 */
void swap(int *a, int l, int h, size_t size)
{
	int tmp;

	tmp = a[l];
	a[l] = a[h];
	a[h] = tmp;
	print_array(a, size);
}
