#include "sort.h"

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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
int *small;
size_t k, o;
if (array == NULL || size < 2)
return;
for (k = 0; k < size - 1; k++)
{
small = array + k;
for (o = k + 1; o < size; o++)
small = (array[o] < *small) ? (array + o) : small;
if ((array + k) != small)
{
swap_intes(array + k, small);
print_array(array, size);
}
}
}
