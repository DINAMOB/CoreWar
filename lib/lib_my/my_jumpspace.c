/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell2-antonie.morel
** File description:
** my_jumpspace
*/

#include "my.h"

char *my_jumpspace(char *str)
{
    int i = 0;

    if (!str)
        return NULL;
    for (i = 0; str[i] && str[i] == ' '; i++);
    return str + i;
}
