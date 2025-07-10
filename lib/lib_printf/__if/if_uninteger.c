/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-myprintf-brandon-jean-samuel.begue
** File description:
** if_uninteger
*/

#include "my_printf.h"

int if_uninteger(va_list list)
{
    data_option_t *tab_op = data_op();
    unsigned int nb = va_arg(list, unsigned int);

    pf_putun_base(nb, "0123456789");
    pf_put(' ', MOINS);
    return 0;
}
