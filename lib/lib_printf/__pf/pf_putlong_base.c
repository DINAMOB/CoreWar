/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** my_putlong_base
*/

#include "my_printf.h"
#include "my.h"

int pf_putlong_base(long nb, char const *base)
{
    long p = 1;
    long div = (long)my_strlen(base);

    if (nb < 0) {
        pf_putchar('-');
        nb *= -1;
    }
    for (; nb / p >= div; p *= div);
    for (; p >= 1; p /= div) {
        pf_putchar(base[nb / p]);
        nb = nb % p;
    }
    return 0;
}
