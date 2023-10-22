#include "sort.h"

void swap_intes(int *a, int *b);
int hoarePartition(int *array, size_t size, int left, int right);
void hoareSort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
* swap_intes - function swap two integers in an array.
* @a: first integer to swap.
* @b: second integer to swap.
*/
void swap_intes(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}

/**
* hoarePartition - function order a subset of an array of integers
*                   according to the hoare partition scheme.
* @array: array.
* @size: size of the array.
* @left: starting index of the subset to order.
* @right: ending index of the subset to order.
* Return: final partition index.
* Description: Uses the last element of the partition as the pivot.
* Prints the array after each swap of two elements.
*/
int hoarePartition(int *array, size_t size, int left, int right)
{
int Pivot, above, below;

Pivot = array[right];
for (above = left - 1, below = right + 1; above < below;)
{
do {
above++;
} while (array[above] < Pivot);
do {
below--;
} while (array[below] > Pivot);

if (above < below)
{
swap_intes(array + above, array + below);
print_array(array, size);
}
}
return (above);
}

/**
* hoareSort - function implement the quicksort algorithm through recursion.
* @array: An array.
* @size: size of the array.
* @left: starting index of the array partition to order.
* @right: ending index of the array partition to order.
* Description: Uses the Hoare partition scheme.
*/
void hoareSort(int *array, size_t size, int left, int right)
{
int partion;

if (right - left > 0)
{
partion = hoarePartition(array, size, left, right);
hoareSort(array, size, left, partion - 1);
hoareSort(array, size, partion, right);
}
}

/**
* quick_sort_hoare - function sort an array of integers in ascending
*                    order using the quicksort algorithm.
* @array: An array.
* @size: size of the array.
* Description: Uses the Hoare partition scheme. Prints
* the array after each swap of two elements.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
hoareSort(array, size, 0, size - 1);
}
