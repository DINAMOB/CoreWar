/*
** EPITECH PROJECT, 2025
** Dinamob Lib_c
** File description:
** my_baselen jan 30
*/

#include "macro.h"

int my_baselen(int nb, int base)
{
    int count = 0;
    int p = 1;

    if (!nb || base <= 0)
        return 0;
    nb = ABS(nb);
    for (; nb / p >= base; p *= base);
    for (; p >= 1; p /= base) {
        count += 1;
        nb = nb % p;
    }
    return count;
}
