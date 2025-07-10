/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_str_isalnum
*/

#include "my.h"

bool my_str_isalnum(char *str)
{
    if (!str)
        return 1;
    for (int i = 0; str[i]; i++)
        if (!isalpha_num(str[i]))
            return 1;
    return 0;
}
