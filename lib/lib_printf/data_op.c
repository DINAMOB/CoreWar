/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-myprintf-brandon-jean-samuel.begue
** File description:
** data_op
*/

#include "my_printf.h"

data_option_t *data_op(void)
{
    static data_option_t tab_op[] = {
        {'#', 0},
        {' ', 0},
        {'-', 0},
        {'+', 0},
        {'0', 0},
        {'.', -1},
        {0, 0}
    };

    return tab_op;
}

void reset_op(void)
{
    data_option_t *tab_op = data_op();

    for (int i = 0; tab_op[i].c != 0; i++)
        tab_op[i].modify = 0;
    tab_op[5].modify = -1;
}
