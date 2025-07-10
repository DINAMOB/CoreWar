/*
** EPITECH PROJECT, 2024
** B-CPE-100-RUN-1-1-cpoolday07-antonie.morel
** File description:
** my_str_isnum
*/

#include "my.h"

bool my_str_isnum(char *str)
{
    if (!str)
        return 0;
    for (int i = 0; str[i]; i++)
        if (!my_isnum(str[i]))
            return 0;
    return 1;
}
