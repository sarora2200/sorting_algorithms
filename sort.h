#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
false = 0,
true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algoritms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);


/* our files */

void swap_intgers(int *I, int *J);
void sort(int *arr, size_t s);
void swapAhead(listint_t **list, listint_t **ta, listint_t **sh);
void swapBehind(listint_t **list, listint_t **ta, listint_t **sh);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
int max_value(int *arr, int s);
void sub_arr(int *sub, int *buff, size_t front, size_t mid, size_t back);
void recursive_sort(int *sub, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
void swap_intGers(int *I, int *J);
void heap_max(int *arr, size_t s, size_t b, size_t ro);
void heap_sort(int *array, size_t size);
int max_radixvalue(int *arr, int s);
void radix_count(int *arr, size_t s, int sig, int *buffer);
void radix_sort(int *array, size_t size);
#endif
