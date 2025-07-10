/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-myprintf-brandon-jean-samuel.begue
** File description:
** if_float
*/

#include "my_printf.h"
#include "my.h"
#include "macro.h"

int if_float(va_list list)
{
    data_option_t *tab_op = data_op();
    int prec = (tab_op[5].modify == -1) ? 6 : tab_op[5].modify;
    double fl = va_arg(list, double);

    pf_putfloat(fl, prec);
    pf_put(' ', MOINS - MAX(my_intlen(fl), POINT) - PLUS);
    return 0;
}
