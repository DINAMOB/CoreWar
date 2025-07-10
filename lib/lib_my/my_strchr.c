/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_strchr
*/

#include <stddef.h>

char *my_strchr(char *str, char c)
{
    int i = 0;

    if (!str)
        return NULL;
    for (i = 0; str[i] && str[i] != c; i++);
    return str + i;
}
