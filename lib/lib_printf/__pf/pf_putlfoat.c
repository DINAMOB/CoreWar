/*
** EPITECH PROJECT, 2025
** Lib_c_skills_Mastery (Workspace)
** File description:
** pf_putlfoat
*/

#include "my_printf.h"

void pf_putfloat(float num, int precision)
{
    int int_part = (int)num;
    float frac_part = 0;

    if (num < 0) {
        pf_putchar('-');
        num = -num;
    }
    frac_part = num - int_part;
    pf_putnbr(int_part);
    pf_putchar('.');
    for (; precision; precision--) {
        frac_part *= 10;
        pf_putchar(((int)frac_part % 10) + '0');
    }
}
