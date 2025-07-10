/*
** EPITECH PROJECT, 2024
** MyLib
** File description:
** pf_puts
*/

#include "my_printf.h"
#include "my.h"
#include "unistd.h"

int pf_puts(char const *str)
{
    int len = my_strlen(str);

    if (write(*pf_output(), str, len) == -1)
        return 0;
    *pf_putchar(0) += len;
    return len;
}
