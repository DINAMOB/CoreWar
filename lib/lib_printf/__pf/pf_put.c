/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** pf_put
*/

#include "my_printf.h"

int pf_put(char c, int precision)
{
    int i = 0;

    for (; i < precision; i++) {
        pf_putchar(c);
    }
    return i;
}
