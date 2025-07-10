/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** pf_putulong
*/

#include "my_printf.h"

int pf_putulong(size_t nb)
{
    size_t p = 1;
    int count = 0;

    for (; nb / p >= 10; p *= 10);
    for (; p >= 1; p /= 10) {
        pf_putchar((nb / p) + 48);
        nb = nb % p;
        count += 1;
    }
    return count;
}
