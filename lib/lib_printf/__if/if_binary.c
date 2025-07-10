/*
** EPITECH PROJECT, 2024
** B-CPE-101-RUN-1-1-myprintf-brandon-jean-samuel.begue
** File description:
** if_binaire
*/

#include "my_printf.h"
#include "my.h"

int if_binaire(va_list list)
{
    unsigned int nb = va_arg(list, unsigned int);
    data_option_t *tab_op = data_op();

    modifier(tab_op, nb, 2);
    pf_putun_base(nb, "01");
    pf_put(' ', tab_op[2].modify - my_intlen(nb) - 1);
    return 0;
}
