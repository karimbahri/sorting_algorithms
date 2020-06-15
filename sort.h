#ifndef __SORT__
#define __SORT__

/*---------------------STRUCTURES---------------------*/

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

/**
 * enum bool - logical type
 * @FALSE: 0
 * @TRUE: 1
 */
typedef enum bool
{
	FALSE,
	TRUE
} bool;

/*---------------------PROTOTYPES---------------------*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **listx, listint_t *tempo);
#endif
