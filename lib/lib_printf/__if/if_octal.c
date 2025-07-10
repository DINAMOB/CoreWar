/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-myprintf-brandon-jean-samuel.begue
** File description:
** if_octal
*/

#include "my_printf.h"
#include "my.h"
#include "macro.h"

int if_octal(va_list list)
{
    data_option_t *tab_op = data_op();
    unsigned int nb = va_arg(list, unsigned int);

    if (SHARP > 0 && nb > 0)
        pf_putchar('0');
    modifier(tab_op, nb, 8);
    pf_putun_base(nb, "01234567");
    pf_put(' ', MOINS - MAX(my_baselen(nb, 8), POINT) - PLUS);
    return 0;
}
