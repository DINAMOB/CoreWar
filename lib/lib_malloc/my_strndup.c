/*
** EPITECH PROJECT, 2024
** LE StrDUP
** File description:
** j'aime malloc
*/

#include "my_malloc.h"
#include "my.h"

char *my_strndup(char const *str, int n)
{
    int i = 0;
    int size = n;
    char *new_str = NULL;

    if (str == NULL || n < 0)
        return NULL;
    if (my_strlen(str) < n)
        size = my_strlen(str);
    new_str = my_malloc(sizeof(char) * (size + 1));
    for (; str[i] != '\0' && i < n; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return new_str;
}
