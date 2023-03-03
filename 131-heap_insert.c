#include "heap.h"
#include <stdlib.h>

/**
 * swap - Swaps two nodes in a heap
 * @n1: A pointer to the first node to swap
 * @n2: A pointer to the second node to swap
 */
static void swap(heap_t *n1, heap_t *n2)
{
    int tmp = n1->n;

    n1->n = n2->n;
    n2->n = tmp;
}

/**
 * heapify_up - Moves a node up the heap until it's in the correct position
 * @heap: A double pointer to the root node of the heap
 * @new: A pointer to the node to move up
 */
static void heapify_up(heap_t **heap, heap_t *new)
{
    heap_t *parent = new->parent;

    while (parent && new->n > parent->n)
    {
        swap(new, parent);
        new = parent;
        parent = new->parent;
    }

    if (!parent)
        *heap = new;
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: A double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new, *parent;

    if (!root)
        return (NULL);

    new = malloc(sizeof(*new));
    if (!new)
        return (NULL);

    new->n = value;
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;

    if (!*root)
        *root = new;
    else
    {
        parent = *root;

        while (parent->left && parent->right)
        {
            if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
                parent = parent->left;
            else
                parent = parent->right;
        }

        if (!parent->left)
            parent->left = new;
        else
            parent->right = new;

        new->parent = parent;

        heapify_up(root, new);
    }

    return (new);
}
