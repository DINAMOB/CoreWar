/*
** EPITECH PROJECT, 2025
** B-MUL-100-RUN-1-1-myradar-antonie.morel
** File description:
** my_dprintf
*/

#include "my_printf.h"

int my_printf(char const *format, ...)
{
    int printf_value = 0;
    va_list list;

    va_start(list, format);
    printf_value = my_vprintf(format, list);
    va_end(list);
    return printf_value;
}
