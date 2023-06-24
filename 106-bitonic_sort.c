#include "sort.h"

void bs(int *array, int end, size_t size, int d);
void merge(int *array, int end, size_t size, int d);
/**
 * bitonic_sort - bitonic sorting algorithm
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */

void bitonic_sort(int *array, size_t size)
{

	if (!array || size < 2)
		return;
	bs(array, size, size, 1);
}

/**
 * bs - bitonic sorting algorithm
 * @array: array to be sorted
 * @end: end point
 * @size: array size
 * @d: direction
 *
 * Return: void
 */
void bs(int *array, int end, size_t size, int d)
{
	int k;
	char *s = "UP";

	if (d == 0)
		s = "DOWN";
	if (end < 2)
		return;

	k = end / 2;
	printf("Merging [%d/%d] (%s):\n", end, (int)size, s);
	print_array(array, end);
	bs(array, k, size, 1);
	bs((array + k), k, size, 0);
	merge(array, end, size, d);
	printf("Result [%d/%d] (%s):\n", end, (int)size, s);
	print_array(array, end);

}

/**
 * merge - bitonic sort auxiliary function
 * @array: array to be sorted
 * @end: new size
 * @size: array size
 * @d: direction
 *
 * Return: void
 */
void merge(int *array, int end, size_t size, int d)
{
	int i, k, tmp;

	if (end > 1)
	{
		k = end / 2;
		for (i = 0; i < k; i++)
		{
			if (d == (array[i] > array[i + k]))
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
			}
		}
		merge(array, k, size, d);
		merge((array + k), k, size, d);
	}
}
