/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** printf_putchar
*/

#include "my_printf.h"
#include <unistd.h>



buffer_data_t *buffering(void)
{
    static buffer_data_t data = {
        .size = 0,
        .str = NULL
    };

    return &data;
}

int *pf_putchar(char c)
{
    static int i = 0;

    if (!c)
        return &i;
    if (buffering()->size)
        buffering()->str[i] = c;
    else if (write(*pf_output(), &c, 1) == -1)
        return &i;
    i += 1;
    return &i;
}
