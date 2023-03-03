#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * is_max_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * @max_value: the maximum value allowed for the node
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree, int max_value)
{
    if (tree == NULL)
        return (1);

    if (tree->n > max_value)
        return (0);

    return (is_max_heap(tree->left, tree->n) &&
            is_max_heap(tree->right, tree->n));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_max_heap(tree, INT_MAX));
}
