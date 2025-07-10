/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-myprintf-brandon-jean-samuel.begue
** File description:
** modifier
*/

#include "my_printf.h"
#include "my.h"

void modifier_for_float(data_option_t *tab_op, double nb, int base)
{
    double len = my_baselen(nb, base);

    if (NONE > 0)
        pf_put(' ', NONE - POINT_COND(POINT) - PLUS);
    if (nb < 0)
        pf_putchar('-');
    if (tab_op[3].modify > 0 && nb >= 0)
        pf_putchar('+');
    for (int i = 0; i < POINT - len || i < ZERO - len - PLUS; i++)
        pf_putchar('0');
}

void modifier_for_size_t(data_option_t *tab_op, size_t nb, int base)
{
    int len = my_baselen_st(nb, base);

    if (NONE > 0)
        pf_put(' ', NONE - POINT_COND(POINT) - PLUS);
    if (PLUS > 0)
        pf_putchar('+');
    for (int i = 0; i < POINT - len || i < ZERO - len - PLUS; i++)
        pf_putchar('0');
}

void modifier(data_option_t *tab_op, int nb, int base)
{
    int len = my_baselen(nb, base);

    len += (len == 0);
    if (NONE > 0)
        pf_put(' ', NONE - POINT_COND(POINT) - PLUS);
    if (nb < 0)
        pf_putchar('-');
    if (PLUS > 0 && nb >= 0)
        pf_putchar('+');
    for (int i = 0; i < POINT - len || i < ZERO - len - PLUS; i++)
        pf_putchar('0');
}
