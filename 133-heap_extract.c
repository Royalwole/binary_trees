#!/bin/bash
/**
 * find_last_node - finds the last level-order node of a binary tree
 * @root: pointer to the root node of the tree
 *
 * Return: pointer to the last node, or NULL on failure
 */
heap_t *find_last_node(heap_t *root)
{
    int level = 0, max_level = 0;
    size_t size;
    heap_t **queue, *node, *last;

    if (root == NULL)
        return (NULL);

    /* Find the maximum level of the tree */
    size = binary_tree_size(root);
    while ((1 << max_level) <= size)
        max_level++;

    /* Allocate a queue to store nodes */
    queue = malloc(sizeof(heap_t *) * size);
    if (queue == NULL)
        return (NULL);

    /* Enqueue the root node */
    queue[level++] = root;

    /* Dequeue nodes until the last level-order node is found */
    while (level <= max_level)
    {
        /* Dequeue a node */
        node = queue[--level];

        /* Update the last node */
        last = node;

        /* Enqueue the left child, if present */
        if (node->left != NULL)
            queue[level + 1 + (node->right != NULL)] = node->left;

        /* Enqueue the right child, if present */
        if (node->right != NULL)
            queue[level + 2

