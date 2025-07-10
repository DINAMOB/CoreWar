/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** my_arrdup
*/

#include "my_malloc.h"
#include "my.h"
#include "macro.h"
#include "my_printf.h"

char **my_arrdup(char **arr)
{
    int len = my_arrlen(arr);
    char **new = NULL;

    if (!arr)
        return NULL;
    new = my_malloc(sizeof(char *) * (len + 1));
    if (!new) {
        my_dprintf(2, "%smy_arrdup: the ptr alloc has failed.\n", ERROR);
        return NULL;
    }
    for (int i = 0; arr[i]; i++)
        new[i] = my_strdup(arr[i]);
    new[len] = NULL;
    return new;
}
