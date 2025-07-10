/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** replacestr
*/

#include "my.h"
#include "my_malloc.h"

char *replacestr(char *str, char *trgt, char *rpl)
{
    int trgt_len = my_strlen(trgt);
    int size = my_strlen(str) - trgt_len + my_strlen(rpl);
    char *new = my_malloc(sizeof(char) * (size + 1));
    int i = 0;

    if (!new)
        return str;
    my_memset(new, 0, size);
    for (i = 0; str[i] && i < size && my_strncmp(str + i, trgt, trgt_len); i++)
        new[i] = str[i];
    for (; i < size && rpl[i]; i++)
        new[i] = rpl[i];
    for (; i < size && str[i + trgt_len - 1]; i++)
        new[i] = str[i + trgt_len - 1];
    my_free(str);
    return new;
}
