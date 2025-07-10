/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-miniprintf-antonie.morel
** File description:
** if_character
*/

#include "my_printf.h"

int if_character(va_list list)
{
    data_option_t *tab_op = data_op();

    pf_put(' ', NONE);
    pf_putchar(va_arg(list, int));
    pf_put(' ', MOINS);
    return 0;
}
