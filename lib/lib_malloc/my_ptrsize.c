/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** my_ptrsize
*/

#include "my_malloc.h"

size_t my_ptrsize(void *ptr)
{
    mem_alloc_t *current = (mem_alloc_t *)*db_mem();
    size_t size = 0;

    for (; current; current = current->next)
        if (current && current->ptr == ptr) {
            size = current->size;
            break;
        }
    return size;
}
