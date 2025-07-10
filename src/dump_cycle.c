/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** dump_cycle
*/

#include "corewar.h"

void dump_cycle(dump_cycle_t *dump, unsigned char *mem)
{
    if (!dump || !mem)
        return;
    if (dump->counter <= 0)
        dump->counter = dump->nb_cycle;
    else
        dump->counter -= 1;
    if (dump->counter <= 0)
        print_memory(mem, MEM_SIZE, 32);
    dump_cycle(dump->next, mem);
}