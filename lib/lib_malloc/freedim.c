/*
** EPITECH PROJECT, 2025
** G-ING-200-RUN-2-1-myworld-antonie.morel
** File description:
** freedim
*/

#include "my_malloc.h"

void freedim(void *tof, int depth, size_t *sizes)
{
    void **ptr = NULL;

    if (depth == 1) {
        my_free(tof);
        return;
    }
    ptr = (void **)tof;
    for (size_t i = 0; i < sizes[0]; i++)
        freedim(ptr[i], depth - 1, sizes + 1);
    my_free(ptr);
}
