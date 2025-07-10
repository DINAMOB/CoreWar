/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_memcpy
*/

#include <stddef.h>
#include "macro.h"

void *my_memcpy(void *RSTCT destptr, const void *RSTCT srcptr, size_t n)
{
    unsigned char *dest = destptr;
    const unsigned char *src = srcptr;

    for (size_t i = 0; i < n; i++)
        dest[i] = src[i];
    return destptr;
}
