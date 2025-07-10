/*
** EPITECH PROJECT, 2024
** B-MUL-100-RUN-1-1-myhunter-antonie.morel
** File description:
** my_malloc
*/

#include "my_malloc.h"
#include "macro.h"
#include "my_printf.h"

/**
 * @brief Allocates memory and keeps track of the allocation.
 *
 * This function allocates a block of memory of
 * the specified size and initializes it to zero.
 * It also records the allocation in a memory tracking structure.
 *
 * @param size Size in bytes of the memory to allocate.
 * @return A pointer to the allocated memory, or NULL on failure.
 */
void *my_malloc(size_t size)
{
    void *ptr = (size > 0) ? malloc(size) : NULL;
    mem_alloc_t *new_alloc = NULL;

    if (ptr) {
        new_alloc = malloc(sizeof(mem_alloc_t));
        if (!new_alloc) {
            my_dprintf(2, "%smy_malloc: the node alloc has failed.\n", ERROR);
            return NULL;
        }
        my_memset(ptr, 0, size);
        new_alloc->ptr = ptr;
        new_alloc->size = size;
        new_alloc->next = *db_mem();
        *db_mem() = new_alloc;
    }
    return ptr;
}

void check_leaks(void)
{
    mem_alloc_t *current = *db_mem();

    if (current == NULL)
        my_printf("Everything is free\n");
    for (; current; current = current->next)
        my_printf("Leaked memory: %p (%d bytes)\n",
        current->ptr, current->size);
}

void clear_mem(void)
{
    mem_alloc_t **current = (mem_alloc_t **)&*db_mem();
    mem_alloc_t *to_free = NULL;

    while (*current) {
        to_free = *current;
        *current = to_free->next;
        if (to_free->ptr)
            free_sc(to_free->ptr);
        free_sc(to_free);
    }
}
