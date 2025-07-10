/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** add_proc
*/

#include "corewar.h"

int proccpy(champ_proc_t *src, champ_proc_t *dest, size_t pc)
{
    char cmd[300] = {0};

    if (!src || !dest)
        return 1;
    my_snprintf(cmd, 300, "%s child", src->name);
    dest->name = my_strdup(cmd);
    if (!dest->name)
        return 1;
    dest->alive = src->alive;
    dest->id = src->id;
    dest->carry = src->carry;
    dest->pc = pc;
    dest->wait_cycle = src->wait_cycle;
    for (int i = 0; i < REG_NUMBER; i++)
        dest->reg[i] = src->reg[i];
    dest->next = NULL;
    return 0;
}

int add_proc(champ_proc_t **current, champ_proc_t *proc, size_t pc)
{
    champ_proc_t *node = NULL;
    champ_proc_t **end = NULL;

    if (!current || !proc)
        return 1;
    node = my_malloc(sizeof(champ_proc_t));
    if (!node || proccpy(proc, node, pc) != 0)
        return my_free(node), 1;
    end = current;
    while (*end)
        end = &(*end)->next;
    *end = node;
    return 0;
}
