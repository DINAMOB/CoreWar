/*
** EPITECH PROJECT, 2024
** LE StrDUP
** File description:
** j'aime malloc
*/

#include "my_malloc.h"
#include "my.h"
#include "my_printf.h"
#include "macro.h"

char *my_strdup(char const *str)
{
    int i = 0;
    char *new_str = NULL;

    if (!str)
        return NULL;
    new_str = my_malloc(sizeof(char) * (my_strlen(str) + 1));
    if (!new_str) {
        my_dprintf(2, "%smy_strdup: the ptr alloc has failed.\n", ERROR);
        return NULL;
    }
    for (; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return new_str;
}
