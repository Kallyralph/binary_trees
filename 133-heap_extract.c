#include "binary_trees.h"
#include <stdio.h>

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;

    if (root == NULL || *root == NULL)
        return (0);

    value = (*root)->n;

    /* Replace root with last level-order node */
    if ((*root)->left != NULL)
    {
        heapify_down(*root);
        *root = find_last_node(*root);
    }
    else
    {
        free(*root);
        *root = NULL;
    }

    return value;
}

/**
 * heapify_down - Moves the new root down until Max Heap property is satisfied
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *current = root;
    heap_t *child;

    while (1)
    {
        child = current->left;

        if (child == NULL)
            break;

        if (current->right != NULL && current->right->n > child->n)
            child = current->right;

        if (child->n <= current->n)
            break;

        swap_values(current, child);

        current = child;
    }
}

/**
 * find_last_node - Finds the last level-order node of the heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the last level-order node
 */
heap_t *find_last_node(heap_t *root)
{
    int mask = 1;
    heap_t *last = root;

    while (last->left != NULL)
    {
        if (mask & root->n)
            last = last->right;
        else
            last = last->left;

        mask <<= 1;
    }

    return last;
}

/**
 * swap_values - Swaps the values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp = a->n;
       	a->n = b->n;
	b->n = temp;
}

