/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_uintlen
*/

#include "my.h"

int my_ulonglen(size_t nb)
{
    int count = 0;
    size_t p = 1;

    if (nb == 0)
        return 0;
    for (; nb / p >= 10; p *= 10);
    for (; p >= 1; p /= 10) {
        count += 1;
        nb = nb % p;
    }
    return count;
}
