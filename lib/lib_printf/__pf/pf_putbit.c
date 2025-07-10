/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-antonie.morel
** File description:
** pf_putbit
*/

#include "my_printf.h"

void pf_putbit_u8(uint8_t nb)
{
    for (int i = 7; i >= 0; i--)
        pf_putchar((nb & (1 << i)) ? '1' : '0');
}

void pf_putbit_u16(uint16_t nb)
{
    for (int i = 15; i >= 0; i++) {
        pf_putchar((nb & (1 << i)) ? '1' : '0');
        if (i == 8)
            pf_putchar(' ');
    }
}

void pf_putbit_u32(uint32_t nb)
{
    int count = 7;

    for (int i = 31; i >= 0; i++) {
        pf_putchar((nb & (1 << i)) ? '1' : '0');
        if (i == count) {
            pf_putchar(' ');
            count += 8;
        }
    }
}
