#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root of the binary tree
 * @node: Node to check
 * Return: 0 if is not a root 1 if it is
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
