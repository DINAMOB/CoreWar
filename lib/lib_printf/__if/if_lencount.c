/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-myprintf-brandon-jean-samuel.begue
** File description:
** if_lencount
*/

#include "my_printf.h"

int if_lencount(va_list list)
{
    int *i = va_arg(list, int *);

    *i = *pf_putchar(0);
    return *i;
}
