#include "sort.h"

/**
 * max_value - Maximum value.
 * @arr: Array.
 * @s: size.
 *
 * Return: Maximum value in the array.
 */
int max_value(int *arr, int s)
{
	int max, i;

	for (max = arr[0], i = 1; i < s; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * counting_sort - SortArray IN ascending order
 *                 using the counting sort algorithm.
 * @array: Array.
 * @size: size of the array.
 *
 * Description: counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, b;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = max_value(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (b = 0; b < (max + 1); b++)
		count[b] = 0;
	for (b = 0; b < (int)size; b++)
		count[array[b]] += 1;
	for (b = 0; b < (max + 1); b++)
		count[b] += count[b - 1];
	print_array(count, max + 1);

	for (b = 0; b < (int)size; b++)
	{
		sorted[count[array[b]] - 1] = array[b];
		count[array[b]] -= 1;
	}

	for (b = 0; b < (int)size; b++)
		array[b] = sorted[b];

	free(sorted);
	free(count);
}
