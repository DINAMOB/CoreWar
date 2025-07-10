/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-corewar-antonie.morel
** File description:
** print_proclist
*/

#include "corewar.h"

void print_proclist(champ_proc_t *proc)
{
    if (!proc)
        return;
    my_printf("Name: %s ID: %d\n", proc->name, proc->id);
    my_printf("Alive: %d\n", proc->alive);
    my_printf("PC: %u\n", proc->pc);
    my_printf("Carry: %d\n", proc->carry);
    my_printf("reg: \n");
    for (int i = 0; i < 16; i++)
        my_printf("[%d] ", proc->reg[i]);
    my_printf("\n");
    my_printf("wait_cycle: %d\n", proc->wait_cycle);
    print_proclist(proc->next);
}
