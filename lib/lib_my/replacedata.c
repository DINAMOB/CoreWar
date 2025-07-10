/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** replacedata
*/

#include "my_malloc.h"

char *replacedata(char *old, char *new)
{
    my_free(old);
    old = my_strdup(new);
    return old;
}
