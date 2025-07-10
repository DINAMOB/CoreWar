/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_memmove
*/

#include <stddef.h>
#include "macro.h"

void *my_memmove(void *RSTCT dest, const void *RSTCT src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if (d < s)
        for (size_t i = 0; i < n; i++)
            d[i] = s[i];
    if (d > s)
        for (size_t i = n; i > 0; i--)
            d[i - 1] = s[i - 1];
    return dest;
}
