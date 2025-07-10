/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-miniprintf-antonie.morel
** File description:
** if_strings
*/

#include "my_printf.h"
#include "my.h"

int if_strings(va_list list)
{
    data_option_t *tab_op = data_op();
    char *str = NULL;
    int prec = 0;

    str = va_arg(list, char *);
    if (str == NULL) {
        pf_puts("(null)");
        return 0;
    }
    prec = (POINT == -1) ? my_strlen(str) : POINT;
    pf_put(' ', NONE - my_strlen(str));
    pf_puts_prec(str, prec);
    pf_put(' ', MOINS - my_strlen(str));
    return 0;
}
