/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** print_dump_cyrcle
*/

#include "corewar.h"

void print_dump_cycle(dump_cycle_t *node)
{
    if (!node)
        return;
    my_printf("dump nb cycle: %d\n", node->nb_cycle);
    print_dump_cycle(node->next);
}
