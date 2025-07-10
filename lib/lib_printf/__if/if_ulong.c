/*
** EPITECH PROJECT, 2024
** B-PSU-100-RUN-1-1-myls-antonie.morel
** File description:
** if_size_t
*/

#include "my_printf.h"
#include "my.h"

int if_ulong(va_list list)
{
    size_t nb = va_arg(list, size_t);
    data_option_t *tab_op = data_op();

    modifier_for_size_t(tab_op, nb, 10);
    pf_putulong(nb);
    pf_put(' ', MOINS - MAX(my_ulonglen(nb), POINT) - PLUS);
    return 0;
}
