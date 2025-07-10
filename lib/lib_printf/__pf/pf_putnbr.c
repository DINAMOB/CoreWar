/*
** EPITECH PROJECT, 2025
** Dinamob Lib_c
** File description:
** pf_putnbr jan 30
*/

#include "my_printf.h"

void pf_putnbr(int n)
{
    if (n < 0) {
        pf_putchar('-');
        if (n == -2147483648) {
            pf_puts("2147483648");
            return;
        }
        n = -n;
    }
    if (n >= 10)
        pf_putnbr(n / 10);
    pf_putchar((n % 10) + '0');
}
