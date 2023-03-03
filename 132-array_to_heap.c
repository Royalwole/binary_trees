/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
    heap_t *root = NULL;
    heap_t *node;
    size_t i;

    if (!array || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        node = heap_insert(&root, array[i]);
        if (!node)
            return (NULL);
    }

    return (root);
}
