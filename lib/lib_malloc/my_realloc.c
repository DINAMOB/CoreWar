/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-42sh-antonie.morel
** File description:
** my_realloc
*/

#include "my_malloc.h"
#include <string.h>

void *my_realloc(void *ptr, size_t new_size)
{
    void *new_ptr = NULL;
    size_t old_size = my_ptrsize(ptr);
    size_t copy_size = 0;

    if (new_size == 0) {
        my_free(ptr);
        return NULL;
    }
    new_ptr = my_malloc(new_size);
    if (!new_ptr)
        return NULL;
    if (ptr != NULL) {
        copy_size = (old_size < new_size) ? old_size : new_size;
        my_memcpy(new_ptr, ptr, copy_size);
        my_free(ptr);
    }
    return new_ptr;
}
