/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_snprintf
*/

#include "my_printf.h"
#include "my_malloc.h"
#include "macro.h"
#include <stddef.h>


int my_snprintf(char *RSTCT str, size_t len, char const *RSTCT format, ...)
{
    int printf_value = 0;
    va_list list;

    va_start(list, format);
    buffering()->size = len;
    buffering()->str = str;
    printf_value = my_vprintf(format, list);
    buffering()->size = 0;
    va_end(list);
    return printf_value;
}
