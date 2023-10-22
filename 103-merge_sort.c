#include "sort.h"

/**
 * sub_arr - Subarray.
 * @sub: subarray to sort.
 * @buffer: buffer.
 * @front_node: front index.
 * @mid_node: middle index.
 * @back_node: back .
 */
void sub_arr(int *sub, int *buffer, size_t front_node, size_t mid_node,
		size_t back_node)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + front_node, mid_node - front_node);

	printf("[right]: ");
	print_array(sub + mid_node, back_node - mid_node);

	for (i = front_node, j = mid_node; i < mid_node && j < back_node; k++)
		buffer[k] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];
	for (; i < mid_node; i++)
		buffer[k++] = sub[i];
	for (; j < back_node; j++)
		buffer[k++] = sub[j];
	for (i = front_node, k = 0; i < back_node; i++)
		sub[i] = buffer[k++];

	printf("[Done]: ");
	print_array(sub + front_node, back_node - front_node);
}

/**
 * recursive_sort - recursion merge sort algorithm.
 * @sub: subarray.
 * @buffer: buffer .
 * @front_node: front.
 * @back_node: back.
 */
void recursive_sort(int *sub, int *buffer, size_t front_node, size_t back_node)
{
	size_t mid_node;

	if (back_node - front_node > 1)
	{
		mid_node = front_node + (back_node - front_node) / 2;
		recursive_sort(sub, buffer, front_node, mid_node);
		recursive_sort(sub, buffer, mid_node, back_node);
		sub_arr(sub, buffer, front_node, mid_node, back_node);
	}
}

/**
 * merge_sort - SortArray in ascending
 *              order using the merge sort algorithm.
 * @array: An array .
 * @size: The size .
 *
 * Description: sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	recursive_sort(array, buffer, 0, size);

	free(buffer);
}
