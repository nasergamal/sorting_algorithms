#include "sort.h"

void heapify(int *array, size_t size, int n, int i);
/**
 * heap_sort - heap sorting algorithm
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i, n, tmp;

	if (!array || size < 2)
		return;

	for (i = (((int)size / 2) - 1); i >= 0; i--)
	{
		heapify(array, size, (int)size, i);
	}
	for (n = ((int)(size) - 1); n >= 0; n--)
	{
		if (n != 0)
		{	tmp = array[n];
			array[n] = array[0];
			array[0] = tmp;
			print_array(array, size);
		}
		heapify(array, size, n, 0);
	}
}

/**
 * heapify - heap sorting algorithm auxiliary function
 * @array: array to be sorted
 * @size: array size
 * @n: size of unsorted segment of array
 * @i: current element in array
 *
 * Return: void
 */
void heapify(int *array, size_t size, int n, int i)
{
	int largest = i, tmp;
	int left = (i * 2) + 1;
	int right = (i * 2) + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		tmp = array[largest];
		array[largest] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, size, n, largest);
	}
}

