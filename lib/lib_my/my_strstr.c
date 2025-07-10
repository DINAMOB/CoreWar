/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell2-antonie.morel
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char *haystack, const char *needle)
{
    int len = my_strlen(needle);
    int i = 0;

    for (i = 0; my_strncmp(haystack + i, needle, len) &&
        haystack[i] != '\0'; i++);
    return (haystack[i] == '\0') ? NULL : haystack + i;
}
