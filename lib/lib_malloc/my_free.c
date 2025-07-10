/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** my_free
*/

#include "my_malloc.h"

size_t my_free(void *ptr)
{
    mem_alloc_t **current = (mem_alloc_t **)&*db_mem();
    mem_alloc_t *to_free = NULL;
    size_t size = 0;

    if (!ptr)
        return 0;
    for (; *current; current = &(*current)->next) {
        if ((*current) && (*current)->ptr == ptr) {
            to_free = *current;
            *current = to_free->next;
            size = to_free->size;
            free_sc(to_free);
            break;
        }
    }
    my_memset(ptr, 0, size);
    free_sc(ptr);
    return size;
}
