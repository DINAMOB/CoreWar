/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-robotfactory-antonie.morel
** File description:
** my_byterev
*/

#include <stdint.h>

uint32_t my_revbyte32s(uint32_t nb, int sel)
{
    uint32_t binary = 0;
    int size = sel * 8;

    for (int i = 0; i < size; i += 8)
        binary |= (((nb >> i) & 255) << ((size - 8) - i));
    return binary;
}
