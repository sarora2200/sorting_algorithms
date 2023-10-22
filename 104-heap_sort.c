#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @I: Integer one.
 * @J: Integer two.
 */
void swap_integers(int *I, int *J)
{
int t;
t = *I;
*I = *J;
*J = t;
}

/**
 * heap_max - Max heapify a binary tree.
 * @arr: Array.
 * @s: Size of the tree.
 * @ro: Root node in the binary tree.
 * @b: Base.
 */
void heap_max(int *arr, size_t s, size_t ro, size_t b)
{
size_t left, right, largest;
largest = ro;
left = 2 * ro + 1;
right = 2 * ro + 2;
if (left < b && arr[left] > arr[largest])
largest = left;
if (right < b && arr[right] > arr[largest])
largest = right;
if (largest != ro)
{
swap_integers(&arr[ro], &arr[largest]);
print_array(arr, s);
heap_max(arr, s, largest, b);
}
}

/**
 * heap_sort - SortArray in ascending order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
int c;
if (array == NULL || size < 2)
return;
for (c = size / 2 - 1; c >= 0; c--)
heap_max(array, size, c, size);
for (c = size - 1; c > 0; c--)
{
swap_integers(&array[0], &array[c]);
print_array(array, size);
heap_max(array, size, 0, c);
}
}
