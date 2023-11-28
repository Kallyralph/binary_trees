#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: num of elements in the array
 *
 * Return: Pointer to the root node of the created Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
   	 heap_t *heap = NULL;
   	 size_t i;

   	 if (size == 0)
       	 return (NULL);

   	 for (i = 0; i < size; i++)
   	 {
		 if (heap_insert(&heap, array[i]) == NULL)
		 {
			 /* If insertion fails, free the heap and return NULL */
			 binary_tree_delete(heap);
			 return (NULL);
		 }
	 }

	 return (heap);
}

