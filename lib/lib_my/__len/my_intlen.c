/*
** EPITECH PROJECT, 2025
** Dinamob Lib_c
** File description:
** my_intlen jan 30
*/

#include "macro.h"

int my_intlen(int nb)
{
    int count = 0;
    int p = 1;

    if (nb == 0)
        return 0;
    nb = ABS(nb);
    for (; nb / p >= 10; p *= 10);
    for (; p >= 1; p /= 10) {
        count += 1;
        nb = nb % p;
    }
    return count;
}
