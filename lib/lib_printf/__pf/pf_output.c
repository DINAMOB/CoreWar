/*
** EPITECH PROJECT, 2025
** B-MUL-100-RUN-1-1-myradar-antonie.morel
** File description:
** pf_output
*/

#include "my_printf.h"

int *pf_output(void)
{
    static int i = 1;

    return &i;
}
