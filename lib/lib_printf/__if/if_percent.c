/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-miniprintf-antonie.morel
** File description:
** if_putpercent
*/

#include "my_printf.h"

int if_percent(va_list list)
{
    (void)list;
    pf_putchar('%');
    return 0;
}
