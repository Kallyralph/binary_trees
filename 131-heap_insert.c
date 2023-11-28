#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
       	heap_t *new_node, *parent;

       	new_node = binary_tree_node(NULL, value);
       	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	parent = find_parent(*root, value);

	new_node->parent = parent;

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify_up(new_node);

	return (new_node);
}

/**
 * find_parent - Finds the parent for the new node
 * @root: Pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root, int value)
{
	int mask = 1;
	heap_t *parent = root;

	while (parent->left != NULL || parent->right != NULL)
	{
		if (mask & value)
		{
			if (parent->right == NULL)
				break;
			parent = parent->right;
		}
		else
		{

			if (parent->left == NULL)
				break;
			parent = parent->left;
		
			
		mask <<= 1;
	}

		return parent;
}

/**
 * heapify_up - Maintains the Max Heap property by swapping the new node with its parent
 * @node: Pointer to the new node
 */
void heapify_up(heap_t *node)
{
	while (node->parent != NULL && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
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

