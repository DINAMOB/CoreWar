/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** my_putstr_prec
*/

#include "my_printf.h"

int pf_puts_prec(char const *str, int precision)
{
    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0' && i < precision; i++)
        pf_putchar(str[i]);
    return 0;
}
