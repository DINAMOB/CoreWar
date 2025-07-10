/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-antonie.morel
** File description:
** if_bits
*/

#include "my_printf.h"

int if_bit8(va_list list)
{
    uint8_t i = va_arg(list, unsigned int);

    pf_putbit_u8(i);
    return 0;
}

int if_bit16(va_list list)
{
    uint16_t i = va_arg(list, unsigned int);

    pf_putbit_u16(i);
    return 0;
}

int if_bit32(va_list list)
{
    uint32_t i = va_arg(list, unsigned int);

    pf_putbit_u32(i);
    return 0;
}
