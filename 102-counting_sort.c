#include "sort.h"

/**
 * counting_sort - counting sorting method
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int largest = 0, n;
	size_t i;
	int *count = NULL, *carray = NULL;

	if (array == NULL || size < 2)
		return;

	carray = malloc(sizeof(int) * size);
	if (carray == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		carray[i] = array[i];
		if (array[i] > largest)
			largest = array[i];
	}
	count = malloc(sizeof(int) * (largest + 1));
	if (count == NULL)
	{
		free(carray);
		return;
	}
	for (n = 0; n <= largest; n++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (n = 1; n <= largest; n++)
		count[n] += count[n - 1];
	print_array(count, largest + 1);
	for (i = 0; i < size; i++)
	{
		array[count[carray[i]] - 1] = carray[i];
		count[carray[i]] -= 1;

	}
	free(carray);
	free(count);
}
