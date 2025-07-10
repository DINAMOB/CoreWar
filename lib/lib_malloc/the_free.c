/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-robotfactory-antonie.morel
** File description:
** the_free
*/

#include "my_malloc.h"

void the_free(void *ptr, int size)
{
    void **arr = (void **)ptr;

    if (!ptr || size < 0)
        return;
    if (size == 1)
        my_free(ptr);
    else {
        for (int i = 0; arr[i]; i++)
            the_free(arr[i], size - 1);
        my_free(arr);
    }
}
