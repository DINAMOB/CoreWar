/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** my_putun_base
*/

#include "my_printf.h"
#include "my.h"

int pf_putun_base(unsigned int nb, char const *base)
{
    unsigned int p = 1;
    unsigned int div = (unsigned int)my_strlen(base);

    for (; nb / p >= div; p *= div);
    for (; p >= 1; p /= div) {
        pf_putchar(base[nb / p]);
        nb = nb % p;
    }
    return 0;
}
