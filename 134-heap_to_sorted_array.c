/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 *
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array, *tmp;
    size_t i, n;

    if (!heap || !size)
        return (NULL);

    n = binary_tree_size(heap);
    array = malloc(n * sizeof(int));
    if (!array)
        return (NULL);

    for (i = 0; i < n; i++)
        array[i] = heap_extract(&heap);

    tmp = realloc(array, n * sizeof(int));
    if (tmp)
        array = tmp;

    *size = n;
    return (array);
}
