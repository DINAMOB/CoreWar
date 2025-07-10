/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-myprintf-brandon-jean-samuel.begue
** File description:
** if_hexadecimal
*/

#include "my_printf.h"
#include "my.h"

int if_hexadecimal(va_list list)
{
    data_option_t *tab_op = data_op();
    int nb = va_arg(list, int);

    modifier(tab_op, nb, 16);
    if (tab_op[0].modify > 0)
        pf_puts("0x");
    pf_putun_base(nb, "0123456789abcdef");
    pf_put(' ', tab_op[2].modify - my_baselen(nb, 16));
    return 0;
}
