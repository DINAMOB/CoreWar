/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** if_hexadecimal
*/

#include "my_printf.h"
#include "my.h"

int if_majhexadecimal(va_list list)
{
    data_option_t *tab_op = data_op();
    int nb = va_arg(list, int);

    modifier(tab_op, nb, 16);
    if (tab_op[0].modify > 0)
        pf_puts("0x");
    pf_putun_base(nb, "0123456789ABCDEF");
    pf_put(' ', tab_op[2].modify - my_baselen(nb, 16));
    return 0;
}
