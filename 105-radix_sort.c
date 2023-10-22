#include "sort.h"

/**
 * max_radixvalue - Maximum value.
 * @arr: Array.
 * @s: size.
 *
 * Return: Maximum.
 */
int max_radixvalue(int *arr, int s)
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
 * radix_count - Sort ascending counting sort algorithm.
 * @arr: Array.
 * @s: size.
 * @sig: sign.
 * @buffer: A buffer to store the sorted array.
 */
void radix_count(int *arr, size_t s, int sig, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < s; i++)
		count[(arr[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = s - 1; (int)i >= 0; i--)
	{
		buffer[count[(arr[i] / sig) % 10] - 1] = arr[i];
		count[(arr[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < s; i++)
		arr[i] = buffer[i];
}

/**
 * radix_sort - Sort ascending using the radix sort algorithm.
 * @array: Array.
 * @size: size.
 *
 * Description: Radix sort algorithm.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = max_radixvalue(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_count(array, size, sig, buffer);
		print_array(array, size);
	}

	free(buffer);
}
