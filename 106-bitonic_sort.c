#include "sort.h"

void swap_intes(int *a, int *b);
void bitonicMerge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonicSeq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_intes - function swap two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_intes(int *a, int *b)
{
int tmep;
tmep = *a;
*a = *b;
*b = tmep;
}

/**
 * bitonicMerge - function sort a bitonic sequence inside an array of integers.
 * @array: An array.
 * @size: size of the array.
 * @start: starting index of the sequence in array to sort.
 * @seq: size of the sequence to sort.
 * @flow: direction to sort in.
 */
void bitonicMerge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
size_t j, go = seq / 2;
if (seq > 1)
{
for (j = start; j < start + go; j++)
{
if ((flow == UP && array[j] > array[j + go]) ||
(flow == DOWN && array[j] < array[j + go]))
swap_intes(array + j, array + j + go);
}
bitonicMerge(array, size, start, go, flow);
bitonicMerge(array, size, start + go, go, flow);
}
}

/**
 * bitonicSeq - function convert an array of integers into a bitonic sequence.
 * @array: An array.
 * @size: size of the array.
 * @start: starting index of a block of the building bitonic sequence.
 * @seq: size of a block of the building bitonic sequence.
 * @flow: direction to sort the bitonic sequence block in.
 */
void bitonicSeq(int *array, size_t size, size_t start, size_t seq, char flow)
{
size_t c = seq / 2;
char *string = (flow == UP) ? "UP" : "DOWN";
if (seq > 1)
{
printf("Merging [%lu/%lu] (%s):\n", seq, size, string);
print_array(array + start, seq);
bitonicSeq(array, size, start, c, UP);
bitonicSeq(array, size, start + c, c, DOWN);
bitonicMerge(array, size, start, seq, flow);
printf("Result [%lu/%lu] (%s):\n", seq, size, string);
print_array(array + start, seq);
}
}

/**
 * bitonic_sort - function sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array.
 * @size: size of the array.
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
bitonicSeq(array, size, 0, size, UP);
}
