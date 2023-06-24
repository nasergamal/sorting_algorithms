#include "sort.h"


void ms(int *array, int start, int end);
void sort(int *array, int start, int middle, int end);

/**
 * merge_sort - merge sorting method
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	ms(array, 0, size - 1);
}

/**
 * ms - merge sorting complimentary function
 * @array: array to be sorted
 * @start: merging start point
 * @end: merging end point
 *
 * Return: void
 */

void ms(int *array, int start, int end)
{
	int m;

	if (start < end)
	{
		m = (start + end - 1) / 2;

		ms(array, start, m);
		ms(array, m + 1, end);

		sort(array, start, m, end);
	}
}

/**
 * sort - merge sorting complimentary function
 * @array: array to be sorted
 * @middle: merging middle point
 * @start: merging start point
 * @end: merging end point
 *
 * Return: void
 */

void sort(int *array, int start, int middle, int end)
{
	int i, n, m;
	int lsize = middle - start + 1, rsize = end - middle;
	int *la, *ra;

	la = malloc(sizeof(int) * lsize);
	ra = malloc(sizeof(int) * rsize);

	printf("Merging...\n[left]:");

	for (i = 0; i < lsize; i++)
	{	la[i] = array[i + start];
		if (i > 0)
			printf(",");
		printf(" %d", la[i]); }
	printf("\n[right]:");
	for (n = 0; n < rsize; n++)
	{
		ra[n] = array[n + middle + 1];
		if (n > 0)
			printf(",");
		printf(" %d", ra[n]);
	}
	printf("\n");
	for (m = start, i = 0, n = 0; i < lsize && n < rsize; m++)
	{
		if (ra[n] <= la[i])
		{	array[m] = ra[n];
			n++; }
		else
		{	array[m] = la[i];
			i++; }
	}
	for (; n < rsize; n++, m++)
		array[m] = ra[n];
	for (; i < lsize; i++, m++)
		array[m] = la[i];
	printf("[Done]:");
	for (m = start; m <= end; m++)
	{
		if (m > start)
			printf(",");
		printf(" %d", array[m]);
	}
	printf("\n"), free(la), free(ra);
}
