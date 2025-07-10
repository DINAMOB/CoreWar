/*
** EPITECH PROJECT, 2024
** B-CPE-110-RUN-1-1-settingup-antonie.morel
** File description:
** if_array
*/

#include "my_printf.h"

int if_array(va_list list)
{
    data_option_t *tab_op = data_op();

    if (tab_op[0].modify > 0)
        pf_putarray_info(va_arg(list, char **));
    else
        pf_putarray(va_arg(list, char **));
    return 0;
}
