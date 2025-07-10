/*
** EPITECH PROJECT, 2025
** G-ING-200-RUN-2-1-myworld-antonie.morel
** File description:
** alloctab
*/

#include "my_malloc.h"

void *allocdim(int dim, size_t *size, size_t block)
{
    void **array = NULL;

    if (dim == 1)
        return my_malloc(block * size[0]);
    array = my_malloc(size[0] * sizeof(void *));
    if (!array)
        return NULL;
    for (size_t i = 0; i < size[0]; i++) {
        array[i] = allocdim(dim - 1, size + 1, block);
        if (!array[i])
            return NULL;
    }
    return (void *)array;
}
