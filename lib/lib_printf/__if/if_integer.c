/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-miniprintf-antonie.morel
** File description:
** if_integer
*/

#include "my_printf.h"
#include "my.h"
#include "macro.h"

int if_integer(va_list list)
{
    int nb = va_arg(list, int);
    data_option_t *tab_op = data_op();

    modifier(tab_op, nb, 10);
    pf_putnbr(ABS(nb));
    pf_put(' ', MOINS - MAX(my_intlen(nb), POINT) - PLUS);
    return 0;
}
