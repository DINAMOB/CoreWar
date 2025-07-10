/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_varlen
*/

#include "my.h"

int my_varlen(int nb, ...)
{
    va_list list;
    char *str = NULL;
    int k = 0;
    int count = 0;

    va_start(list, nb);
    for (int i = 0; i < nb; i++) {
        str = va_arg(list, char *);
        for (k = 0; str[k]; k++);
        count += k;
    }
    va_end(list);
    return count;
}
