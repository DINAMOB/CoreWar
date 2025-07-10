/*
** EPITECH PROJECT, 2025
** Dinamob Lib_c
** File description:
** my_arrlen jan 30
*/

#include <stddef.h>

int my_arrlen(char **arr)
{
    int i = 0;

    if (!arr)
        return i;
    for (; arr[i] != NULL; i++);
    return i;
}
