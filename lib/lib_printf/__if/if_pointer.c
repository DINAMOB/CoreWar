/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-myprintf-brandon-jean-samuel.begue
** File description:
** if_pointer
*/

#include "my_printf.h"

int if_pointer(va_list list)
{
    void *p = va_arg(list, void *);
    long nb = (long)p;

    if (p == NULL) {
        pf_puts("(nil)");
        return 0;
    }
    pf_puts("0x");
    pf_putlong_base(nb, "0123456789abcdef");
    return 0;
}
