/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** print_memory
*/

#include "corewar.h"

void print_pack(unsigned char *mem, int size, int package, int i)
{
    int lim = 0;

    for (int j = 0; j < package; j++) {
        if (i + j < size)
            my_printf("%02X ", mem[i + j]);
        if (lim == 7) {
            my_printf(" ");
            lim = -1;
        }
        lim++;
    }
}

void print_memory(unsigned char *mem, int size, int package)
{
    if (!mem)
        return;
    pf_put('-', 12 + (package * 3));
    my_printf("\n");
    for (int i = 0; i < size; i += package) {
        my_printf("%08X: ", i);
        print_pack(mem, size, package, i);
        my_printf("\n");
    }
    pf_put('-', 8 + (package * 2));
    my_printf("\n");
}
