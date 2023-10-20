#include "sort.h"

void swap_intes(int *a, int *b);
int lom_partition(int *array, size_t size, int left, int right);
void lom_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_intes - function swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_intes(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}

/**
 * lom_partition - function order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */
int lom_partition(int *array, size_t size, int left, int right)
{
int *pivot, above, below;
pivot = array + right;
for (above = below = left; below < right; below++)
{
if (array[below] < *pivot)
{
if (above < below)
{
swap_intes(array + below, array + above);
print_array(array, size);
}
above++;
}
}
if (array[above] > *pivot)
{
swap_intes(array + above, pivot);
print_array(array, size);
}
return (above);
}

/**
 * lom_sort - function implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Lomuto partition scheme.
 */
void lom_sort(int *array, size_t size, int left, int right)
{
int partion;
if (right - left > 0)
{
partion = lom_partition(array, size, left, right);
lom_sort(array, size, left, partion - 1);
lom_sort(array, size, partion + 1, right);
}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
lom_sort(array, size, 0, size - 1);
}
