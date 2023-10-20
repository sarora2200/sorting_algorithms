#include "sort.h"

/**
 * swap_intes - function to swap two integers in an array.
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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
size_t j, len = size;
bool bubbles = false;
if (array == NULL || size < 2)
return;
while (bubbles == false)
{
bubbles = true;
for (j = 0; j < len - 1; j++)
{
if (array[j] > array[j + 1])
{
swap_intes(array + j, array + j + 1);
print_array(array, size);
bubbles = false;
}
}
len--;
}
}
