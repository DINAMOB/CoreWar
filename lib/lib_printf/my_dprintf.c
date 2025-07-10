/*
** EPITECH PROJECT, 2025
** B-MUL-100-RUN-1-1-myradar-antonie.morel
** File description:
** my_dprintf
*/

#include "my_printf.h"

int my_dprintf(int output, char const *format, ...)
{
    int printf_value = 0;
    va_list list;

    va_start(list, format);
    *pf_output() = output;
    printf_value = my_vprintf(format, list);
    *pf_output() = 1;
    va_end(list);
    return printf_value;
}
