#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_swap - Swaps two nodes in a binary heap
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void heap_swap(heap_t *a, heap_t *b)
{
    int tmp;

    tmp = a->n;
    a->n = b->n;
    b->n = tmp;
}

/**
 * heapify - Recursive function that reorders a binary heap
 * @node: Pointer to the root node of the heap
 */
void heapify(heap_t *node)
{
    heap_t *max = node;

    if (node->left != NULL && node->left->n > max->n)
        max = node->left;
    if (node->right != NULL && node->right->n > max->n)
        max = node->right;
    if (max != node)
    {
        heap_swap(node, max);
        heapify(max);
    }
}

/**
 * heap_insert - Inserts a value in a binary heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node = binary_tree_node(*root, value);

    if (node == NULL)
        return (NULL);
    if (*root == NULL)
        return (*root = node);
    else
    {
        heap_t *parent = *root;
        size_t size = binary_tree_size(*root) + 1;

        while (size / 2 > 1)
        {
            parent = (size % 2 == 0) ? parent->left : parent->right;
            size /= 2;
        }
        if (size == 2)
            parent = parent->left;
        else if (size == 3)
            parent = parent->right;
        node->parent = parent;
        if (parent->left == NULL)
            parent->left = node;
        else
            parent->right = node;
        while (node->parent != NULL && node->n > node->parent->n)
        {
            heap_swap(node, node->parent);
            node = node->parent;
        }
        return (node);
    }
}
