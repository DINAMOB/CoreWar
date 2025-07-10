/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell1-antonie.morel
** File description:
** my_isalpha_num
*/

#include "my.h"

bool isalpha_num(char c)
{
    if ((c >= 'a' && c <= 'z')
    || (c >= 'A' && c <= 'Z')
    || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}
