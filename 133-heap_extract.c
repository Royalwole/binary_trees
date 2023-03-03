#include "binary_trees.h"

/**
 * tree_size - Calculates the size of a binary tree
 *
 * @tree: A pointer to the root node of the tree to calculate the size of
 *
 * Return: The size of the tree, 0 if tree is NULL
 */
static size_t tree_size(const heap_t *tree)
{
    if (!tree)
        return (0);

    return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * swap_values - Swaps the values of two nodes
 *
 * @node1: A pointer to the first node
 * @node2: A pointer to the second node
 */
static void swap_values(heap_t *node1, heap_t *node2)
{
    int tmp = node1->n;

    node1->n = node2->n;
    node2->n = tmp;
}

/**
 * heapify_down - Restores the heap property starting from the root node
 *
 * @root: A double pointer to the root node of the heap
 */
static void heapify_down(heap_t **root)
{
    heap_t *node = *root, *max_child;

    while (node->left)
    {
        max_child = node->left;

        if (node->right && node->right->n > max_child->n)
            max_child = node->right;

        if (node->n >= max_child->n)
            break;

        swap_values(node, max_child);
        node = max_child;
    }
}

/**
 * get_last_node - Returns a pointer to the last level-order node of a heap
 *
 * @root: A pointer to the root node of the heap
 *
 * Return: A pointer to the last level-order node, or NULL if the heap is empty
 */
static heap_t *get_last_node(heap_t *root)
{
    size_t size = tree_size(root), index = 0;
    heap_t **queue = malloc(sizeof(heap_t *) * size), *node;

    if (!queue)
        return (NULL);

    queue[index] = root;
    while (index < size)
    {
        node = queue[index];
        index++;

        if (node->left)
            queue[index] = node->left;

        if (node->right)
            queue[index] = node->right;
    }

    node = queue[size - 1];
    free(queue);

    return (node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 *
 * @root: A double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 if the heap is empty
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last_node = get_last_node(*root);

    if (*root == last_node)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    (*root)->n = last_node->n;
    if (last_node->parent->right)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    free(last_node);
    heapify_down(root);

    return (value);
}
