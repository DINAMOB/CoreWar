/*
** EPITECH PROJECT, 2024
** lol
** File description:
** fatigue
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    if (dest == NULL || src == NULL)
        return NULL;
    for (; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
