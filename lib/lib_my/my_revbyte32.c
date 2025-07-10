/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-robotfactory-antonie.morel
** File description:
** my_byterev
*/

#include <stdint.h>

uint32_t my_revbyte32(uint32_t nb)
{
    uint32_t binary = 0;

    for (int i = 0; i < 32; i += 8)
        binary |= (((nb >> i) & 255) << ((32 - 8) - i));
    return binary;
}
