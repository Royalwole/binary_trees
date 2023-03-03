/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of heap
 *
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node, *parent;

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

    parent = get_parent(*root, last_node);
    if (parent->right)
        parent->right = NULL;
    else
        parent->left = NULL;
    (*root)->n = last_node->n;
    free(last_node);
    if (parent->left == NULL || parent->left->n > parent->right->n)
        swap_node(parent->left, parent->right);
    max_heapify(parent->left);
    max_heapify(parent->right);

    return (value);
}
