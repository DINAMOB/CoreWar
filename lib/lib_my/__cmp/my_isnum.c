/*
** EPITECH PROJECT, 2024
** B-PSU-100-RUN-1-1-mytop-antonie.morel
** File description:
** my_isnum
*/

#include "my.h"

bool my_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}
