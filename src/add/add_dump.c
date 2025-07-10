/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** add_dump
*/

#include "corewar.h"

int add_dump(dump_cycle_t **current, int nb)
{
    dump_cycle_t *node = my_malloc(sizeof(dump_cycle_t));

    if (!node)
        return 1;
    node->nb_cycle = nb;
    node->next = *current;
    *current = node;
    return 0;
}
