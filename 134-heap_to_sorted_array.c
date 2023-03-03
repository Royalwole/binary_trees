#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 *
 * @heap: Pointer to the root node of the heap to convert
 * @size: Pointer to store the size of the array
 *
 * Return: Pointer to the sorted array of integers, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t i;

    if (heap == NULL || size == NULL)
        return (NULL);

    *size = binary_tree_size(heap);
    array = malloc(*size * sizeof(int));
    if (array == NULL)
        return (NULL);

    for (i = 0; i < *size; i++)
    {
        array[i] = heap_extract(&heap);
    }

    return (array);
}
