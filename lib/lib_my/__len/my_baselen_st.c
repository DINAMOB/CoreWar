/*
** EPITECH PROJECT, 2025
** Dinamob Lib_c
** File description:
** my_baselen_st jan 30
*/

#include "stddef.h"

int my_baselen_st(size_t nb, int base)
{
    int count = 0;
    size_t p = 1;

    if (!nb || base <= 0)
        return 0;
    for (; nb / p >= (size_t)base; p *= base);
    for (; p >= 1; p /= base) {
        count += 1;
        nb = nb % p;
    }
    return count;
}
