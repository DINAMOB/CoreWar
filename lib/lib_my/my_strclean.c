/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-robotfactory-antonie.morel
** File description:
** my_strclean
*/

#include "my.h"
#include "my_malloc.h"

char *my_strclean(char *str, char *trgt)
{
    int l = 0;
    char *new = NULL;

    if (!str)
        return NULL;
    for (int i = 0; str[i]; i++)
        if (!if_same(str[i], trgt))
            l++;
    new = my_malloc(sizeof(char) * (l + 1));
    if (!new)
        return NULL;
    l = 0;
    for (int i = 0; str[i]; i++)
        if (!if_same(str[i], trgt)) {
            new[l] = str[i];
            l++;
        }
    new[l] = '\0';
    return new;
}
