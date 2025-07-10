/*
** EPITECH PROJECT, 2025
** B-PSU-100-RUN-1-1-mysudo-antonie.morel
** File description:
** replacechr
*/

#include "my.h"

/**
 * @brief replace char in strings by another select.
 *
 * @param str strings allocate.
 * @param trgt target char to replace.
 * @param rpl new value of target.
 * @return int 84 error(str == NULL), 0 no problem.
 */
int replacechr(char *str, char trgt, char rpl)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i]; i++)
        if (str[i] == trgt)
            str[i] = rpl;
    return 0;
}
