#include "sort.h"


void count_sort(int *array, size_t size, int i);

/**
 * radix_sort - radix sorting algorithm
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int i, max;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (i = 1; max / i > 0; i *= 10)
		count_sort(array, size, i);
}

/**
 * count_sort - radix sorting algorithm auxiliary count sorting function
 * @array: array to be sorted
 * @size: array size
 * @i: number of digit
 *
 * Return: void
 */
void count_sort(int *array, size_t size, int i)
{
	int n, m, max = (array[0] / i) % 10;
	size_t j;
	int *carray = NULL, count[10];

	carray = malloc(sizeof(int) * size);
	if (carray == NULL)
		exit(1);
	for (j = 0; j < size; j++)
	{
		carray[j] = array[j];
		if (max < (array[j] / i) % 10)
			max = array[j];
	}
	for (n = 0; n < 10; n++)
		count[n] = 0;
	for (j = 0; j < size; j++)
		count[(array[j] / i) % 10] += 1;
	for (n = 1; n < 10; n++)
		count[n] += count[n - 1];
	for (m = size - 1; m >= 0; m--)
	{
		array[count[(carray[m] / i) % 10] - 1] = carray[m];
		count[(carray[m] / i) % 10] -= 1;
	}
	free(carray);
	print_array(array, size);
}
