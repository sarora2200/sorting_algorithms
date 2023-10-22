#include "sort.h"

/**
 * swap_intgers - SwapIntegers in Array.
 * @I: Integer One.
 * @J: Integer Two.
 */
void swap_intgers(int *I, int *J)
{
	int t;

	t = *I;
	*I = *J;
	*J = t;
}

/**
 * shell_sort - SortArray ascending
 * @arr: Array.
 * @s: Size Array.
 *
 * Description: Ascending Sort Of Array.
 */
void shell_sort(int *arr, size_t s)
{
	size_t gap, i, j;

	if (arr == NULL || s < 2)
		return;

	for (gap = 1; gap < (s / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < s; i++)
		{
			j = i;
			while (j >= gap && arr[j - gap] > arr[j])
			{
				swap_intgers(arr + j, arr + (j - gap));
				j -= gap;
			}
		}
		print_array(arr, s);
	}
}
